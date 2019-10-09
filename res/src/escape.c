#include "ud_string.h"

char    *ud_str_escape(char *str)
{
    int     i = 0;
    int     j = ud_str_len(str) - 1;

    if (!str || !str[0]) return (str);
    if (str[i] == '\"' && str[j] == '\"') return ud_str_sub(str, i + 1, j - 1);
    if (str[i] == '\'' && str[j] == '\'') return ud_str_sub(str, i + 1, j - 1);
    return (str);
}