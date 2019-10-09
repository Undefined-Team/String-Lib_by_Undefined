#include "ud_string.h"

char    *ud_str_fjoin(char *head, char *tail)
{
    char    *join = ud_str_join(head, tail);
    ud_ut_free(tail);
    ud_ut_free(head);
    return join;
}