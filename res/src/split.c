#include "ud_string.h"

ud_list_define(ud_str_split_len, ud_list_default_free, NULL);

static int                  ud_str_cmp_ofst(char **p1, char *p2, size_t *offset)
{
    unsigned char *s1 = *(unsigned char**)p1;
    unsigned char *s2 = (unsigned char*)p2;
    size_t new_off = 0;
    while (*s1 && *s2 && *s1 == *s2)
    {
        ++s1;
        ++s2;
        ++new_off;
    }
    *offset = new_off + (new_off == 0);
    *p1 = (char*)s1 + ((char*)s1 == *p1);
    if (!*s2) return 0;
    return *s1 - *s2;
}

ud_str_split_len   *ud_str_split_get_len(char *val, char *sep, size_t *split_len)
{
    ud_str_split_len  *begin    = ud_list_init(ud_str_split_len, len = 0);
    ud_str_split_len  *tmp      = begin;
    size_t            offset;
    size_t            split_len_tmp = 0;
    ud_ut_count i = 0;
    while (*val)
    {
        if (!ud_str_cmp_ofst(&val, sep, &offset))
        {
            tmp = ud_list_push(tmp, len = i);
            i = 0;
            ++split_len_tmp;
        }
        else
            i += offset;
    }
    *split_len = split_len_tmp;
    tmp = ud_list_push(tmp, len = i);
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
    else if (!sep || !*sep)
    {
        size_t len = ud_str_len(str);
        char **ret = ud_ptr_init(char*, len);
        for (char **elem = ret; len-- > 0; ) *elem++ = ud_ut_array(char, *str++, '\0');
        return ret;
    }
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
        ud_ut_prot_malloc(arr_str = ud_ut_malloc(sizeof(char) * (tmp->len + 1)));
        arr_str[tmp->len] = '\0';
        ud_mem_cpy_rs(arr_str, str, tmp->len);
        *arr_val = arr_str;
        str += sep_len;
        ++arr_val;
    }
    ud_list_free(ud_str_split_len, begin);
    return new_arr;
}

char **ud_str_rsplit(char *str, char **floor_sep)
{
    if (!floor_sep || !*floor_sep) return NULL;
    char **splitted = ud_str_split(str, *floor_sep);
    char **splitted_tmp = splitted;
    ++floor_sep;
    if (*floor_sep)
    {
        char **new_val;
        while (*splitted_tmp)
        {
            new_val = ud_str_rsplit(*splitted_tmp, floor_sep);
            ud_ut_free(*splitted_tmp);
            *(char***)splitted_tmp++ = new_val;
        }
    }
    return splitted;
}