#include "ud_string.h"

ud_arr  *ud_str_sub(ud_arr *str, size_t start, size_t len)
{
    ud_arr  *sub;

    if (!str)
        ud_ut_error("%s", "Null array provided.");
    sub = ud_arr_init(sizeof(char), len);
    char *sub_a = (char *)sub->val;
    char *str_a = (char *)&(((char *)str->val)[start]);
    for (ud_ut_count i = 0; i < len; ++i, ++sub_a, ++str_a)
        *sub_a = *str_a;
    return (sub);
}