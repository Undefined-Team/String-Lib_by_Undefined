#include "ud_string.h"

char    *ud_str_cat(char *head, char *tail)
{
    char    *cat;
    if (!head) return ud_str_dup(tail);
    else if (!tail) return ud_str_dup(head);
    size_t  head_len = ud_str_len(head);
    size_t  tail_len = ud_str_len(tail);
    ud_ut_prot_malloc(cat = ud_ut_malloc(sizeof(char) * (head_len + tail_len + 1)));
    char    *p_cat = cat;
    for (; *head; ++p_cat, ++head)
        *p_cat = *head;
    for (; *tail; ++p_cat, ++tail)
        *p_cat = *tail;
    *p_cat = 0;
    return cat;
}