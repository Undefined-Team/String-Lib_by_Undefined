#include "ud_string.h"

int     ud_str_cmp(ud_arr *s1, ud_arr *s2)
{
    if (!s1)
        ud_ut_error("%s", "Null array provided as first argument.");
    else if (!s2)
        ud_ut_error("%s", "Null array provided as second argument.");
    if (!s1->val)
        return -1;
    else if (!s2->val)
        return 1;
    unsigned char *a_s1 = (unsigned char *)s1->val;
    unsigned char *a_s2 = (unsigned char *)s2->val;
    
    for (; *a_s1 && *a_s2 && *a_s1 == *a_s2; a_s1++, a_s2++);
    return *a_s1 - *a_s2;
}