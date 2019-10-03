#include "ud_string.h"

ud_arr  *ud_str_fjoin(ud_arr *head, ud_arr *tail)
{
    ud_arr  *join;

    if (!head->val || head->len == 0)
        return ud_str_fdup(tail, tail->len);
    else if (!tail->val || tail->len == 0)
        return ud_str_fdup(head, head->len);
    join = ud_arr_init(sizeof(char), head->len + tail->len);
    char *join_a = (char *)join->val;
    char *head_a = (char *)head->val;
    char *tail_a = (char *)tail->val;
    for (; *head_a; ++join_a, ++head_a)
        *join_a = *head_a;
    for (; *tail_a; ++join_a, ++tail_a)
        *join_a = *tail_a;
    ud_arr_free(tail);
    ud_arr_free(head);
    return join;
}