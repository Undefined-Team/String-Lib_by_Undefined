#include "ud_string.h"

char  *ud_str_fndup(char *str, size_t len)
{
    char  *dup;

    dup = ud_str_dup_l(str, len);
    ud_ut_free(str);
    return (dup);
}