#include "ud_string.h"

int     ud_str_chr(ud_arr *str, char c)
{
    if (!str)
        ud_ut_error("%s", "Null array provided.");
    if (!str->val)
        return -1;
    char    *a_str = (char *)str->val;

    for (; *a_str; ++a_str)
        if (*a_str == c)
            return a_str - (char *)str->val;
    return -1;
}