#include "ud_string.h"

int     ud_str_chr(char *str, char c)
{
    if (!str) return -1;
    char *begin = str;
    for (; *str; ++str)
        if (*str == c) return str - begin;
    return -1;
}