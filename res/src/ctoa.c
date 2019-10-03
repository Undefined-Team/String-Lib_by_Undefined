#include "ud_string.h"

ud_arr  *ud_str_ctoa(char c)
{
    return ud_arr_set(char, 2, c, 0);
}