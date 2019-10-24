#include "ud_string.h"

char    *ud_str_fill(char c, size_t len)
{
    char    *str;

    ud_ut_prot_malloc(str = ud_ut_malloc(sizeof(char) * (len + 1)));
    ud_mem_set(str, c, len);
    str[len] = '\0';
    return (str);
}