#include "../sv/string-view.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
	{ // Compare with c-string
		char* cstring = "this is a c string";
		StringView same_sv = SV_construct(cstring);
		StringView difference_sv = SV_construct("this is a different c string");
		StringView different_size_sv = SV_construct("this is a j string");

		assert( SV_compare_cstr(&same_sv, cstring) );
		assert( SV_compare_cstr(&difference_sv, cstring) == 0 );
		assert( SV_compare_cstr(&different_size_sv, cstring) == 0 );
	}

	{ // Compare with other string views
		StringView base_sv = SV_construct("this is a c string");
		StringView same_sv = SV_construct("this is a c string");
		StringView difference_sv = SV_construct("this is a different c string");
		StringView different_size_sv = SV_construct("this is a j string");

		assert( SV_compare_sv(&base_sv, &same_sv) );
		assert( SV_compare_sv(&base_sv, &difference_sv) == 0 );
		assert( SV_compare_sv(&base_sv, &different_size_sv) == 0 );
	}

	{ // Normal test
		char* t1 = "Hello, world!";
		StringView SV_t1 = SV_construct(t1);

		// Prefix
		SV_prefix(&SV_t1, 3);
		assert( SV_compare_cstr(&SV_t1, "Hel") );

		// Suffix
		SV_t1 = SV_construct(t1);
		SV_suffix(&SV_t1, 3);
		assert( SV_compare_cstr(&SV_t1, "ld!") );

		// Split
		SV_t1 = SV_construct(t1);
		StringView Sv_two = SV_split(&SV_t1, ',');
		assert( SV_compare_cstr(&SV_t1, "Hello") );
		assert( SV_compare_cstr(&Sv_two, " world!") );

		// Prefix with large count
		SV_t1 = SV_construct(t1);
		SV_prefix(&SV_t1, 500);
		assert( SV_compare_cstr(&SV_t1, t1) );

		// Suffix with large count
		SV_t1 = SV_construct(t1);
		SV_suffix(&SV_t1, 500);
		assert( SV_compare_cstr(&SV_t1, t1) );
	}

	{ // With empty string
		char* t1 = "";
		StringView SV_t1 = SV_construct(t1);

		// Prefix
		SV_prefix(&SV_t1, 3);
		assert( SV_compare_cstr(&SV_t1, t1) );

		// Suffix
		SV_t1 = SV_construct(t1);
		SV_suffix(&SV_t1, 3);
		assert( SV_compare_cstr(&SV_t1, t1) );

		// Prefix with large count
		SV_t1 = SV_construct(t1);
		SV_prefix(&SV_t1, 500);
		assert( SV_compare_cstr(&SV_t1, t1) );

		// Suffix with large count
		SV_t1 = SV_construct(t1);
		SV_suffix(&SV_t1, 500);
		assert( SV_compare_cstr(&SV_t1, t1) );
	}

	{ // Whitespace stripping
		StringView sv = SV_construct("    this has things       ");
		SV_strip_whitespace(&sv);
		assert( SV_compare_cstr(&sv, "this has things") );

		StringView spaces = SV_construct("          ");
		SV_strip_whitespace(&spaces);
		assert( SV_compare_cstr(&spaces, "") );
	}

	{ // Split without delimiter
		StringView sv = SV_construct("this has no comma");
		StringView split = SV_split(&sv, ',');
		assert( SV_compare_sv(&sv, &split) );
	}

	return 0;
}
