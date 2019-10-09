#include "ud_string.h"

char  *ud_str_dup_l(char *str, size_t len)
{
    char  *dup;

    if (!str) return NULL;
    if (!len) len = ud_ut_str_len(str);
    UD_UT_PROT_MALLOC(dup = ud_ut_malloc(sizeof(char) * (len + 1)));
    ud_mem_cpy(dup, str, len + 1);
    return (dup);
}