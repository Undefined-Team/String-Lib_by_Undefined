#include "ud_string.h"

char    *ud_str_join_ctr(char **str, char *sep, ud_bool need_free)
{
    if (!str) return ud_str_dup("");  
    size_t sep_len = ud_str_len(sep);
    size_t total_len = 0;
    char **str_tmp = str;
    size_t str_nbr = ud_ptr_len((void**)str);
    while (*str_tmp) total_len += ud_str_len(*str_tmp++);
    total_len += sep_len * (str_nbr - 1);
    char *res;
    UD_UT_PROT_MALLOC(res = ud_ut_malloc(sizeof(char) * (total_len + 1)));
    char *res_tmp = res;
    str_tmp = str;
    --str_nbr;
    if (need_free)
    {
        for (ud_ut_count i = 0; i < str_nbr; ++i)
        {
            ud_str_cpy_rd(res_tmp, *str_tmp);
            ud_ut_free(*str_tmp++);
            ud_str_cpy_rd(res_tmp, sep);
        }
        ud_str_cpy_rd(res_tmp, *str_tmp);
        ud_ut_free(*str_tmp++);
    }
    else
    {
        for (ud_ut_count i = 0; i < str_nbr; ++i)
        {
            ud_str_cpy_rd(res_tmp, *str_tmp++);
            ud_str_cpy_rd(res_tmp, sep);
        }
        ud_str_cpy_rd(res_tmp, *str_tmp);
    }
    *res_tmp = '\0';
    if (need_free) ud_ut_free(str);
    return res;
}

char    *ud_str_rjoin_ctr(char **str, char **sep, ud_bool need_free)
{
    ++sep;
    char **str_tmp = str;
    if (*sep)
        for (; *str_tmp; ++str_tmp)
            *str_tmp = ud_str_rjoin_ctr((char**)*str_tmp, sep, need_free);
    return ud_str_join_ctr(str, *(sep - 1), need_free);
}