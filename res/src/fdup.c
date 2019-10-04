#include "ud_string.h"

ud_arr  *ud_str_fdup(ud_arr *str, size_t len)
{
    ud_arr  *dup;

    if (!str)
        ud_ut_error("%s", "Null array provided.");
    dup = ud_arr_init(sizeof(char), str->len);
    char *a_dup = (char *)dup->val;
    char *a_str = (char *)str->val;
    for (ud_ut_count i = 0; i < len; ++i, ++a_dup, ++a_str)
        *a_dup = *a_str;
    ud_arr_free(str);
    return (dup);
}