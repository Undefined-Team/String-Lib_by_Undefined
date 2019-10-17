#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <ud_pointer.h>

// Macro
# define ud_str_is_white_space(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\v' || (c) == '\f' || (c) == '\0')
# define ud_str_dup(str)            ud_str_ndup(str, 0)
# define ud_str_fdup(str)           ud_str_fndup(str, 0)
# define ud_str_cpy_rd(dst, src)    ud_str_cpy_rd_ctr(&dst, src)

# define ud_str_vrsplit(str, ...)   ({ char *sep[] = {__VA_ARGS__, NULL}; char **ret = ud_str_rsplit(str, sep); ret; })

# define ud_str_join(str, sep)      ud_str_join_ctr(str, sep, false)
# define ud_str_fjoin(str, sep)     ud_str_join_ctr(str, sep, true)
# define ud_str_vjoin(sep, ...)     ({ char *str[] = {__VA_ARGS__, NULL}; char *ret = ud_str_join(str, sep); ret; })

# define ud_str_rjoin(str, sep)     ud_str_rjoin_ctr((char**)str, sep, false)
# define ud_str_rfjoin(str, sep)    ud_str_rjoin_ctr((char**)str, sep, true)

# define ud_str_vrjoin(str, ...)    ({ char *sep[] = {__VA_ARGS__, NULL}; char *ret = ud_str_rjoin(str, sep); ret; })
# define ud_str_vrfjoin(str, ...)   ({ char *sep[] = {__VA_ARGS__, NULL}; char *ret = ud_str_rfjoin(str, sep); ret; })

// Structures
typedef struct                      uds_str_split_len {
    size_t                          len;
    struct uds_str_split_len        *next;
}                                   ud_str_split_len;        

// Prototypes
int                                 ud_str_chr(char *str, char c);
int                                 ud_str_cmp(char *s1, char *s2);
char                                *ud_str_ctoa(char c);
char                                *ud_str_ndup(char *str, size_t len);
char                                *ud_str_fndup(char *str, size_t len);
char                                *ud_str_fill(char c, size_t len);
char                                *ud_str_fcat(char *head, char *tail);
char                                *ud_str_fsub(char *str, size_t start, size_t len);
char                                *ud_str_cat(char *head, char *tail);
char                                *ud_str_sub(char *str, size_t start, size_t len);
void                                ud_str_split_free_len(ud_str_split_len *begin);
ud_str_split_len                    *ud_str_split_get_len(char *val, char *sep, size_t *split_len);
char                                **ud_str_split(char *str, char *sep);
char                                **ud_str_rsplit(char *str, char **floor_sep);
char                                *ud_str_join_ctr(char **str, char *sep, ud_bool need_free);
char                                *ud_str_rjoin_ctr(char **str, char **sep, ud_bool need_free);
size_t                              ud_str_len(char *str);
char                                *ud_str_escape(char *str);
char                                *ud_str_whitespace(char *str);
void                                ud_str_cpy(char *dst, char *src);
void                                ud_str_cpy_rd_ctr(char **dst, char *src);

#endif