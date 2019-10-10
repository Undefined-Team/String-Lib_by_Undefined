#include "ud_string.h"

char    *ud_str_fcat(char *head, char *tail)
{
    char    *cat = ud_str_cat(head, tail);
    ud_ut_free(tail);
    ud_ut_free(head);
    return cat;
}