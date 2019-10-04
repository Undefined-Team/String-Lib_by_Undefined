#include "ud_string.h"

ud_arr  *ud_str_fill(char c, size_t len)
{
    ud_arr  *str;

    str = ud_arr_init(sizeof(char), len);
    char *a_str = (char*)str->val;
    for (ud_ut_count i = 0; i < len; i++, ++a_str)
        *a_str = c;
    *a_str = '\0';
    return (str);
}