#include "ud_string.h"

ud_arr  *ud_str_escape(ud_arr *str)
{
    int     i = 0;
    int     j = ud_str_len(str) - 1;

    if (!str->val || str->len == 0)
        return (str);
    char *a_str = (char*)str->val;
    if (a_str[i] == '\"' && a_str[j] == '\"')
        return (ud_str_sub(str, i + 1, j - 1));
    if (a_str[i] == '\'' && a_str[j] == '\'')
        return (ud_str_sub(str, i + 1, j - 1));
    return (str);
}