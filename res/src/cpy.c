#include "ud_string.h"

void        ud_str_cpy(char *dst, char *src)
{
    while (*src) *dst++ = *src++;
}

void        ud_str_cpy_rd(char **dst, char *src)
{
    char *dstc = *dst;
	while (*src) *dstc++ = *src++;
    *dst = dstc;
}