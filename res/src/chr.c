#include "ud_string.h"

int     ud_str_chr(ud_arr *str, char c)
{
    if (!str)
        ud_ut_error("%s", "Null array provided.");
    if (!str->val)
        return -1;
    char    *str_a = (char *)str->val;

    for (; *str_a; ++str_a)
        if (*str_a == c)
            return str_a - (char *)str->val;
    return -1;
}