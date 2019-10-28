#include "ud_string.h"

char    *ud_str_sub(char *str, size_t start, size_t len)
{
    char    *sub;

    if (start > ud_str_len(str)) return ud_str_dup("");
    if (!str) return NULL;
    ud_ut_prot_malloc(sub = ud_ut_malloc(sizeof(char) * (len + 1)));
    char *p_sub = sub;
    str = str + start;
    for (ud_ut_count i = 0; i < len && *str; ++i)
        *p_sub++ = *str++;
    *p_sub = '\0';
    return (sub);
}