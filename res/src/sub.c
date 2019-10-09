#include "ud_string.h"

char    *ud_str_sub(char *str, size_t start, size_t len)
{
    char    *sub;

    if (!str) return NULL;
    UD_UT_PROT_MALLOC(sub = ud_ut_malloc(sizeof(char) * (len + 1));
    char *p_sub = sub;
    for (ud_ut_count i = 0; i < len && *str; ++i, ++p_sub, ++str)
        *p_sub = *str;
    return (sub);
}