#include "ud_string.h"

char  *ud_str_fsub(char *str, size_t start, size_t len)
{
    char *sub = ud_str_sub(str, start, len);
    ud_ut_free(str);
    return (sub);
}