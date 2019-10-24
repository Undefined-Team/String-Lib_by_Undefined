#include "ud_string.h"

char  *ud_str_ndup(char *str, size_t len)
{
    char  *dup;

    if (!str) return NULL;
    if (!len) len = ud_str_len(str);
    ud_ut_prot_malloc(dup = ud_ut_malloc(sizeof(char) * (len + 1)));
    ud_mem_cpy(dup, str, len + 1);
    return (dup);
}