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
    char    *s1_a = (char *)s1->val;
    char    *s2_a = (char *)s2->val;
    
    for (; *s1_a && *s2_a && *s1_a == *s2_a; s1_a++, s2_a++);
    return (unsigned char)*s1_a - (unsigned char)*s2_a;
}