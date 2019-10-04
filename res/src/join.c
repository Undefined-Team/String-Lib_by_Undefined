#include "ud_string.h"

ud_arr  *ud_str_join(ud_arr *head, ud_arr *tail)
{
    ud_arr  *join;

    if (!head->val || head->len == 0)
        return ud_str_dup(tail, tail->len);
    else if (!tail->val || tail->len == 0)
        return ud_str_dup(head, head->len);
    join = ud_arr_init(sizeof(char), head->len + tail->len);
    char *a_join = (char *)join->val;
    char *a_head = (char *)head->val;
    char *a_tail = (char *)tail->val;
    for (; *a_head; ++a_join, ++a_head)
        *a_join = *a_head;
    for (; *a_tail; ++a_join, ++a_tail)
        *a_join = *a_tail;
    return join;
}