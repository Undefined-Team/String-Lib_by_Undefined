#include "ud_string.h"

ud_arr  *ud_str_ctoa(char c)
{
    ud_arr *ret = ud_arr_set(char, 2, c, 0);
    return ret;
}