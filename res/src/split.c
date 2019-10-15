#include "ud_string.h"

static ud_str_split_len     *ud_str_split_new_len(size_t len)
{
    ud_str_split_len *new;
    UD_UT_PROT_MALLOC(new = ud_ut_malloc(sizeof(ud_str_split_len)));
    new->len = len;
    new->next = NULL;
    return new;
}

void                ud_str_split_free_len(ud_str_split_len *begin)
{
    ud_str_split_len *tmp;
    while (begin)
    {
        tmp = begin;
        begin = begin->next;
        ud_ut_free(tmp);
    }
}

static int                  ud_str_cmp_ofst(char **p1, char *p2, size_t *offset)
{
    unsigned char *s1 = *(unsigned char**)p1;
    unsigned char *s2 = (unsigned char*)p2;
    *offset = 1;
    while (*s1 && *s2 && *s1 == *s2)
    {
        ++s1;
        ++s2;
        ++(*offset);
    }
    *p1 = (char*)s1;
    if (!*s2) return 0;
    return *s1 - *s2;
}

ud_str_split_len   *ud_str_split_get_len(char *val, char *sep, size_t *split_len)
{
    ud_str_split_len  *begin  = ud_str_split_new_len(0);
    ud_str_split_len  *tmp    = begin;
    size_t            offset;
    ud_ut_count i = 0;
    while (*val)
    {
        if (!ud_str_cmp_ofst(&val, sep, &offset))
        {
            tmp->next = ud_str_split_new_len(i);
            i = 0;
            tmp = tmp->next;
            ++(*split_len);
        }
        else
        {
            i += offset;
            ++val;
        }
    }
    tmp->next = ud_str_split_new_len(i);
    ++(*split_len);
    return begin;
}

char                        **ud_str_split(char *str, char *sep)
{
    if (!str) return NULL;
    else if (!*str) 
    {
        char **ret = ud_ut_malloc(sizeof(char*) * 2); 
        ret[0] = ud_str_dup("");
        ret[1] = NULL;
        return ret;
    }
    else if (!sep || !*sep) ud_ut_error("Separator can't be null");
    size_t              split_len   = 0;
    size_t              sep_len     = ud_str_len(sep);
    ud_str_split_len    *begin      = ud_str_split_get_len(str, sep, &split_len);
    if (!split_len)     ud_str_dup(str);
    char                **new_arr   = ud_ut_malloc(sizeof(char*) * (split_len + 1));
    new_arr[split_len] = NULL;
    char                **arr_val   = new_arr;
    char                *arr_str;
    for (ud_str_split_len *tmp = begin->next; tmp; tmp = tmp->next)
    {
        UD_UT_PROT_MALLOC(arr_str = ud_ut_malloc(sizeof(char) * (tmp->len + 1)));
        arr_str[tmp->len] = '\0';
        ud_mem_cpy_rs(arr_str, (void**)&str, tmp->len);
        *arr_val = arr_str;
        str += sep_len;
        ++arr_val;
    }
    ud_str_split_free_len(begin);
    return new_arr;
}