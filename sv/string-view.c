#include "string-view.h"
#include <stdlib.h>
#include <string.h>

StringView SV_construct(const char *cstr) {
	return (StringView) {
		.string = cstr,
		.length = strlen(cstr)
	};
}

void SV_prefix(StringView *sv, size_t count) {
	if (count > sv->length) count = sv->length;
	sv->length = count;
}

void SV_suffix(StringView *sv, size_t count) {
	if (count > sv->length) count = sv->length;
	sv->string += (sv->length - count);
	sv->length = count;
}

StringView SV_split(StringView *sv, char delim) {
	size_t i = 0;
	while (i < sv->length && sv->string[i] != delim) {
		++i;
	}

	if (i >= sv->length) {
		return (StringView) {
			.string = sv->string,
			.length = sv->length
		};
	}

	StringView ret = {
		.string = sv->string + i + 1,
		.length = sv->length - i - 1
	};

	sv->length = i;

	return ret;
}

void SV_strip_whitespace(StringView *sv) {
	while (sv->length > 0 && sv->string[0] == ' ') {
		++sv->string;
		--sv->length;
	}

	while (sv->length > 0 && sv->string[sv->length - 1] == ' ') {
		--sv->length;
	}
}

bool SV_compare_sv(const StringView *sv1, const StringView *sv2) {
	if (sv1->length != sv2->length) return false;

	for (size_t i = 0; i < sv1->length; ++i) {
		if (sv1->string[i] != sv2->string[i]) return false;
	}

	return true;
}

bool SV_compare_cstr(const StringView* sv, const char* cstr) {
	if (sv->length != strlen(cstr)) return false;

	for (size_t i = 0; i < sv->length; ++i) {
		if (sv->string[i] != cstr[i]) return false;
	}

	return true;
}
