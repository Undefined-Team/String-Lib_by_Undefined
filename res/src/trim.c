#include "ud_string.h"

static size_t ud_str_trim_a(char *str, size_t str_len, char *trim, size_t trim_len)
{
    printf("trim len = %zd, str len = %zd\n", trim_len, str_len);
    if (trim_len > str_len) return 0;
    printf("test strncmp = %d\n", ud_str_ncmp(str, trim, trim_len));
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

void        ud_str_trim_len(char *str, size_t **trim_len)
{
    *(*trim_len)++ = ud_str_len(str);
}

char        *ud_str_trim_ctr(char *str, char **trim, size_t *trim_len, ud_bool need_free)
{
    size_t str_len = ud_str_len(str);
    size_t dec_a = 0;
    printf("TRIM = %s\n", *trim);
    if (trim)
    {
        char *ptr_a = str;
        char *ptr_b = str + str_len;
        size_t index;
        do {
            index = ud_str_trim_loop_a(ptr_a, str_len, trim, trim_len);
            printf("index = %zd\n", index);
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
    printf("test trimed = %s\n", new);
    return new;
}