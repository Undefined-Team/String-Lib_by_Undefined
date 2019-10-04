#include "ud_string.h"

ud_arr  *ud_str_sub(ud_arr *str, size_t start, size_t len)
{
    ud_arr  *sub;

    if (!str)
        ud_ut_error("%s", "Null array provided.");
    sub = ud_arr_init(sizeof(char), len);
    char *a_sub = (char *)sub->val;
    char *a_str = (char *)&(((char *)str->val)[start]);
    for (ud_ut_count i = 0; i < len; ++i, ++a_sub, ++a_str)
        *a_sub = *a_str;
    return (sub);
}