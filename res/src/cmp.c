#include "ud_string.h"

int     ud_str_cmp(char *p1, char *p2)
{
    if (!p1)
        return -1;
    else if (!p2)
        return 1;
    unsigned char *s1 = (unsigned char *)p1;
    unsigned char *s2 = (unsigned char *)p2;
    
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2);
    return *s1 - *s2;
}

int     ud_str_ncmp(char *p1, char *p2, size_t n)
{
    if (!p1)
        return -1;
    else if (!p2)
        return 1;
    unsigned char *s1 = (unsigned char *)p1;
    unsigned char *s2 = (unsigned char *)p2;
    for (ud_ut_count i = 0; *s1 && *s2 && *s1 == *s2 && i++ < n; ++s1, ++s2);
    return *s1 - *s2;
}