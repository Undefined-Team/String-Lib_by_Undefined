#include "ud_string.h"

char    *ud_str_join(char *head, char *tail)
{
    char    *join;

    if (!head) return ud_str_fdup(tail);
    else if (!tail) return ud_str_fdup(head);
    size_t  head_len = ud_str_len(head);
    size_t  tail_len = ud_str_len(tail);
    UD_UT_PROT_MALLOC(join = ud_ut_malloc(sizeof(char) * (head_len + tail_len + 1)));
    char    *p_join = join;
    for (; *head; ++p_join, ++head)
        *p_join = *head;
    for (; *tail; ++p_join, ++tail)
        *p_join = *tail;
    return join;
}