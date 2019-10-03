#include "ud_string.h"

ud_arr  *ud_str_whitespace(ud_arr *str)
{
    ud_ut_count     i = 0;
    ud_ut_count     j = ud_str_len(str) - 1;

    char *str_a = (char*)str->val;
    if (!str_a || str->len == 0)
        return (str);
    while (ud_is_white_space(str_a[i]))
        i++;
    while (ud_is_white_space(str_a[j]))
        j--;
    return (ud_str_sub(str, i, j - i + 1));
}