#include "ud_string.h"

void        ud_str_cpy(char *dst, char *src)
{
    if (!src || !dst) return;
    while (*src) *dst++ = *src++;
}

void        ud_str_cpy_rd_ctr(char **dst, char *src)
{
    if (!src || !dst) return;
    char *dstc = *dst;
	while (*src) *dstc++ = *src++;
    *dst = dstc;
}