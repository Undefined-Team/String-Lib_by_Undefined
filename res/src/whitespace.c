#include "ud_string.h"

char    *ud_str_whitespace(char *str)
{
    ud_ut_count     i = 0;
    ud_ut_count     j = ud_str_len(str) - 1;

    char *a_str = (char*)str->val;
    if (!a_str || str->len == 0)
        return (str);
    while (ud_str_is_white_space(a_str[i]))
        i++;
    while (ud_str_is_white_space(a_str[j]))
        j--;
    return (ud_str_sub(str, i, j - i + 1));
}