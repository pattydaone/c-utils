#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
	const char *string;
	size_t length;
} StringView;

StringView SV_construct(const char *inp);

void SV_prefix(StringView *str, size_t len);

void SV_suffix(StringView *str, size_t len);

StringView SV_split(StringView *sv, char delim);

void SV_strip_whitespace(StringView *sv);

bool SV_compare_sv(const StringView *sv1, const StringView *sv2);

bool SV_compare_cstr(const StringView* sv, const char* cstr);

#endif
