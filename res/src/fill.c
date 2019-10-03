#include "ud_string.h"

ud_arr  *ud_str_fill(char c, size_t len)
{
    ud_arr  *str;

    str = ud_arr_init(sizeof(char), len);
    char *str_a = (char*)str->val;
    for (ud_ut_count i = 0; i < len; i++, ++str_a)
        *str_a = c;
    *str_a = '\0';
    return (str);
}