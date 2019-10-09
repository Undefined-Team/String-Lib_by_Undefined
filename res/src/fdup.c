#include "ud_string.h"

char  *ud_str_fndup(char *str, size_t len)
{
    char  *dup;

    dup = ud_str_ndup(str, len);
    ud_ut_free(str);
    return (dup);
}