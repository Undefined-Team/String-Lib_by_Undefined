#include "ud_string.h"

ud_arr  *ud_str_dup(ud_arr *str, size_t len)
{
    ud_arr  *dup;

    if (!str)
        ud_ut_error("%s", "Null array provided.");
    dup = ud_arr_init(sizeof(char), str->len);
    char *dup_a = (char *)dup->val;
    char *str_a = (char *)str->val;
    for (ud_ut_count i = 0; i < len; ++i, ++dup_a, ++str_a)
        *dup_a = *str_a;
    return (dup);
}