#include "ud_string.h"

char    *ud_str_ctoa(char c)
{
    char    *ret;
    ud_ut_prot_malloc(ret = ud_ut_malloc(2 * sizeof(char)));
    ret[0] = c;
    ret[1] = '\0';
    return ret;
}