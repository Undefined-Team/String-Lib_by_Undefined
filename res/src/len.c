#include "ud_string.h"

size_t  ud_str_len(ud_arr *str)
{
    ud_ut_count     i = 0;
    char            *a_str = (char *)str->val;

    for (; *a_str; ++i, ++a_str);
    return (i);
}