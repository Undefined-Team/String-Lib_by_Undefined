#include "ud_string.h"

static size_t ud_str_trim_a(char *str, size_t str_len, char *trim, size_t trim_len)
{
    if (trim_len > str_len) return 0;
    return ud_str_ncmp(str, trim, trim_len) ? 0 : trim_len;
}

static size_t ud_str_trim_loop_a(char *str, size_t str_len, char **trim, size_t *trim_len)
{
    size_t index = 0;
    while (!index && *trim)
        index = ud_str_trim_a(str, str_len, *trim++, *trim_len++);
    return index;
}

static size_t ud_str_trim_b(char *str, size_t str_len, char *trim, size_t trim_len)
{
    if (trim_len > str_len) return 0;
    str -= trim_len;
    return ud_str_ncmp(str, trim, trim_len) ? 0 : trim_len;
}

static size_t ud_str_trim_loop_b(char *str, size_t str_len, char **trim, size_t *trim_len)
{
    size_t index = 0;
    while (!index && *trim)
        index = ud_str_trim_b(str, str_len, *trim++, *trim_len++);
    return index;
}

char        *ud_str_trim_main_ctr(char *str, char **trim, size_t *trim_len, ud_bool need_free)
{
    size_t str_len = ud_str_len(str);
    size_t dec_a = 0;
    if (trim)
    {
        char *ptr_a = str;
        char *ptr_b = str + str_len;
        size_t index;
        do {
            index = ud_str_trim_loop_a(ptr_a, str_len, trim, trim_len);
            ptr_a += index;
            dec_a += index;
            str_len -= index;
        } while (index);
        do {
            index = ud_str_trim_loop_b(ptr_b, str_len, trim, trim_len);
            ptr_b -= index;
            str_len -= index;
        } while (index);
    }
    char *new = ud_str_sub(str, dec_a, str_len);
    if (need_free) ud_ut_free(str);
    return new;
}

char    *ud_str_trim_ctr(char *str, char **trim, ud_bool need_free)
{
    size_t trim_len[ud_ptr_len(trim)];
    size_t *trim_len_tmp = trim_len;
    ud_ptr_foreach(trim, elem, *trim_len_tmp++ = ud_str_len(*elem););
    return ud_str_trim_main_ctr(str, trim, trim_len, need_free);
}

// char    *ud_str_rtrim_ctr(char **strs, char **trim, size_t *trim_lem, ud_bool need_free)
// {
//     //CE SERT UNIQUEMENT DE TRIM_MAIN_CTR et ctrim se sert de cette fonction en copiant tout
//     return NULL;
// }