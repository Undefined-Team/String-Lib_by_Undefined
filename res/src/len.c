#include "ud_string.h"

size_t  ud_str_len(char *str)
{
    if (!str) return 0;
    ud_ut_count i = 0;
    for (; *str; ++str, ++i);
    return i;
}