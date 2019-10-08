#include "ud_string.h"

static ud_str_split_len     *ud_str_split_new_len(size_t len)
{
    ud_str_split_len *new;
    UD_UT_PROT_MALLOC(new = ud_ut_malloc(sizeof(ud_str_split_len)));
    new->len = len;
    new->next = NULL;
    return new;
}

static void                ud_str_split_free_len(ud_str_split_len *begin)
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
    // *offset -= *offset == 0 ? 0 : 1; 
    if (!*s2) return 0;
    return *s1 - *s2;
}

static ud_str_split_len   *ud_str_get_split_len(char *val, char *sep, size_t *split_len)
{
    ud_str_split_len  *begin  = ud_str_split_new_len(0);
    ud_str_split_len  *tmp    = begin;
    size_t            offset;
    // for (ud_ut_count i = 0; *val; ++val, ++i)
    // {
    //     if (!ud_str_cmp_ofst(&val, sep, &offset))
    //     {
    //         printf("i = %zd & *val = %c\n", i, *val);
    //         tmp->next = ud_str_split_new_len(i);
    //         i = 0;
    //         tmp = tmp->next;
    //         ++(*split_len);
    //     }
    //     else i += offset;
    //     if (!*val) break;
    // }
    ud_ut_count i = 0;
    while (*val)
    {
        if (!ud_str_cmp_ofst(&val, sep, &offset))
        {
            printf("entre\n");
            tmp->next = ud_str_split_new_len(i);
            i = 0;
            tmp = tmp->next;
            ++(*split_len);
        }
        else
        {
            printf("pas entre\n");
            i += offset;
            ++val;
        }
        printf("i = %zd & *val = %c\n", i, *val);
    }
    tmp->next = ud_str_split_new_len(i);
    ++(*split_len);
    return begin;
}

ud_arr                      *ud_str_split(ud_arr *str, char *sep)
{
    if (str->type_s != sizeof(char)) ud_ut_error("str argument must be an array of char");
    else if (!sep || !*sep) ud_ut_error("separator can't be null");
    size_t              split_len   = 0;
    size_t              sep_len     = ud_ut_byte_len(sep);
    char                *val        = (char*)str->val;
    ud_str_split_len    *begin      = ud_str_get_split_len(val, sep, &split_len);
    printf("split len = %zd\n", split_len);
    printf("sep len = %zd\n", sep_len);
    if (!split_len)     return str; 
    ud_arr              *new_arr    = ud_arr_init(0, split_len);
    ud_arr              **arr_val   = (ud_arr**)new_arr->val;
    char                *arr_str;
    for (ud_str_split_len *tmp = begin->next; tmp; tmp = tmp->next)
    {
        printf("tmp len %zd\n", tmp->len);
        UD_UT_PROT_MALLOC(arr_str = ud_ut_malloc(sizeof(char) * (tmp->len + 1)));
        arr_str[tmp->len] = '\0';
        printf("str = %s\n", val);
        val = ud_mem_cpy_rs(arr_str, val, tmp->len);
        // (*arr_val)->val = arr_str;
        *arr_val = ud_arr_new(sizeof(char), tmp->len, arr_str);
        val += sep_len;
        ++arr_val;
    }
    ud_str_split_free_len(begin);
    return new_arr;
}