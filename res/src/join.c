#include "ud_string.h"

char    *ud_str_join(char **str, char *sep)
{
    if (!str) return ud_str_dup("");
    size_t sep_len = ud_str_len(sep);
    size_t total_len = 0;
    char **str_tmp = str;
    size_t str_nbr = ud_ut_ptr_len((void**)str);
    size_t strs_len[str_nbr];
    size_t *strs_len_tmp = strs_len;
    while (*str_tmp)
    {
        *strs_len_tmp = ud_str_len(*str_tmp++);
        total_len += *strs_len_tmp++;
    }
    total_len += sep_len * (str_nbr - 1);
    char *res;
    UD_UT_PROT_MALLOC(res = ud_ut_malloc(sizeof(char) * (total_len + 1)));
    char *res_tmp = res;
    str_tmp = str;
    strs_len_tmp = strs_len;
    --str_nbr;
    for (ud_ut_count i = 0; i < str_nbr; ++i)
    {
        res_tmp = ud_mem_cpy_rd(res_tmp, *str_tmp++, *strs_len_tmp++);
        res_tmp = ud_mem_cpy_rd(res_tmp, sep, sep_len);
    }
    res_tmp = ud_mem_cpy_rd(res_tmp, *str_tmp++, *strs_len_tmp++);
    *res_tmp = '\0';
    return res;
}