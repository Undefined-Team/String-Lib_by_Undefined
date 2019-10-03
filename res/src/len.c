#include "ud_string.h"

size_t  ud_str_len(ud_arr *str)
{
    ud_ut_count     i = 0;
    char            *str_a = (char *)str->val;

    for (; *str_a; ++i, ++str_a);
    return (i);
}