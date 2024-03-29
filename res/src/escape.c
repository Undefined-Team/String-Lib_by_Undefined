#include "ud_string.h"

char    *ud_str_escape_ctr(char *str, ud_bool need_free)
{
    if (!str || !str[0]) return (str);
    int     i = 0;
    int     j = ud_str_len(str) - 1;

    char *ret = str;
    if (str[i] == '\"' && str[j] == '\"' && i != j) ret = ud_str_sub(str, i + 1, j - 1);
    if (str[i] == '\'' && str[j] == '\'' && i != j) ret = ud_str_sub(str, i + 1, j - 1);
    if (need_free && ret != str) ud_ut_free(str);
    return (ret);
}