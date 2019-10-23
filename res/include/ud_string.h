#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <stdarg.h>
#include <ud_pointer.h>
#include <ud_list.h>

// Macro
# define ud_str_is_white_space(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\v' || (c) == '\f' || (c) == '\0')
# define ud_str_dup(str)            ud_str_ndup(str, 0)
# define ud_str_fdup(str)           ud_str_fndup(str, 0)
# define ud_str_cpy_rd(dst, src)    ud_str_cpy_rd_ctr(&dst, src)

// # define ud_str_trim(str, _trim)    ({ size_t trim_len[ud_ptr_len(_trim)]; size_t *trim_len_tmp = trim_len; ud_ptr_fp(_trim, ud_str_trim_len, &trim_len_tmp); ud_str_trim_ctr(str, _trim, trim_len, false); })
// # define ud_str_ftrim(str, _trim)   ({ size_t trim_len[ud_ptr_len(_trim)]; size_t *trim_len_tmp = trim_len; ud_ptr_fp(_trim, ud_str_trim_len, &trim_len_tmp); ud_str_trim_ctr(str, _trim, trim_len, true); })

# define ud_str_trim(str, trim)     ud_str_trim_ctr(str, trim, false)
# define ud_str_ftrim(str, trim)    ud_str_trim_ctr(str, trim, true)

# define ud_str_vtrim(str, ...)     ({ char *trim[] = {__VA_ARGS__, NULL}; ud_str_trim(str, trim); })
# define ud_str_vftrim(str, ...)    ({ char *trim[] = {__VA_ARGS__, NULL}; ud_str_ftrim(str, trim); })

# define ud_str_rtrim(strs, _trim)
# define ud_str_rftrim(strs, _trim)

# define ud_str_

# define ud_str_vrsplit(str, ...)   ({ char *sep[] = {__VA_ARGS__, NULL}; ud_str_rsplit(str, sep); })

# define ud_str_join(str, sep)      ud_str_join_ctr(str, sep, false)
# define ud_str_fjoin(str, sep)     ud_str_join_ctr(str, sep, true)
# define ud_str_vjoin(sep, ...)     ({ char *str[] = {__VA_ARGS__, NULL}; ud_str_join(str, sep); })
# define ud_str_vfjoin(sep, ...)    ({ char **str = ud_ut_array(char *, __VA_ARGS__, NULL); ud_str_fjoin(str, sep); })

# define ud_str_rjoin(str, sep)     ud_str_rjoin_ctr((char**)str, sep, false)
# define ud_str_rfjoin(str, sep)    ud_str_rjoin_ctr((char**)str, sep, true)

# define ud_str_vrjoin(str, ...)    ({ char *sep[] = {__VA_ARGS__, NULL}; ud_str_rjoin(str, sep); })
# define ud_str_vrfjoin(str, ...)   ({ char *sep[] = {__VA_ARGS__, NULL}; ud_str_rfjoin(str, sep); })

// Structures
typedef struct                      uds_str_split_len {
    void                            (*fp_free)(void *val);
    struct uds_str_split_len        *next;
    size_t                          len;
}                                   ud_str_split_len;

// Prototypes
int                                 ud_str_chr(char *str, char c);
int                                 ud_str_cmp(char *s1, char *s2);
int                                 ud_str_ncmp(char *s1, char *s2, size_t n);
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
char                                *ud_str_trim_main_ctr(char *str, char **trim, size_t *trim_len, ud_bool need_free);
char                                *ud_str_trim_ctr(char *str, char **trim, ud_bool need_free);
void                                ud_str_trim_len(char *str, size_t **trim_len);

#endif