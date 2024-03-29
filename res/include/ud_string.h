#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <stdarg.h>
#include <ud_pointer.h>
#include <ud_list.h>

// Macro
# define ud_str_is_white_space(_c)          ({ __auto_type _ct = _c; ((_ct) == ' ' || (_ct) == '\t' || (_ct) == '\n' || (_ct) == '\v' || (_ct) == '\f' || (_ct) == '\0'); })
# define ud_str_dup(_str)                   ud_str_ndup(_str, 0)
# define ud_str_fdup(_str)                  ud_str_fndup(_str, 0)
# define ud_str_cpy_rd(_dst, _src)          ud_str_cpy_rd_ctr(&(_dst), _src)

# define ud_str_escape(_str)                ud_str_escape_ctr(_str, false)
# define ud_str_fescape(_str)               ud_str_escape_ctr(_str, true)

# define ud_str_trim(_str, _trim)           ud_str_trim_ctr(_str, _trim, false)
# define ud_str_ftrim(_str, _trim)          ud_str_trim_ctr(_str, _trim, true)
# define ud_str_rtrim(_str, _depth, _trim)  ud_str_rtrim_ctr((char**)(_str), _depth, _trim)

# define ud_str_vtrim(_str, ...)            ({ char *_trim[] = {__VA_ARGS__, NULL}; ud_str_trim(_str, _trim); })
# define ud_str_vftrim(_str, ...)           ({ char *_trim[] = {__VA_ARGS__, NULL}; ud_str_ftrim(_str, _trim); }) 
# define ud_str_vrtrim(_str, _depth, ...)   ({ char *_trim[] = {__VA_ARGS__, NULL}; ud_str_rtrim(_str, _depth, _trim); })

# define ud_str_vrsplit(_str, ...)          ({ char *_sep[] = {__VA_ARGS__, NULL}; ud_str_rsplit(_str, _sep); })

# define ud_str_join(_str, _sep)            ud_str_join_ctr(_str, _sep, false)
# define ud_str_fjoin(_str, _sep)           ud_str_join_ctr(_str, _sep, true)
# define ud_str_vjoin(_sep, ...)            ({ char *_str[] = {__VA_ARGS__, NULL}; ud_str_join(_str, _sep); })
# define ud_str_vfjoin(_sep, ...)           ({ char **_str = ud_ut_array(char *, __VA_ARGS__, NULL); ud_str_fjoin(_str, _sep); })

# define ud_str_rjoin(_str, _sep)           ud_str_rjoin_ctr((char**)(_str), _sep, false)
# define ud_str_rfjoin(_str, _sep)          ud_str_rjoin_ctr((char**)(_str), _sep, true)

# define ud_str_vrjoin(_str, ...)           ({ char *_sep[] = {__VA_ARGS__, NULL}; ud_str_rjoin(_str, _sep); })
# define ud_str_vrfjoin(_str, ...)          ({ char *_sep[] = {__VA_ARGS__, NULL}; ud_str_rfjoin(_str, _sep); })

// Structures
ud_list_struct(ud_str_split_len, size_t len);
/*
typedef struct                      sud_str_split_len {
    struct sud_str_split_len        *next;
    size_t                          len;
}                                   ud_str_split_len;
*/

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
char                                *ud_str_escape_ctr(char *str, ud_bool need_free);
char                                *ud_str_whitespace(char *str);
void                                ud_str_cpy(char *dst, char *src);
void                                ud_str_cpy_rd_ctr(char **dst, char *src);
char                                *ud_str_trim_main_ctr(char *str, char **trim, size_t *trim_len, ud_bool need_free);
char                                *ud_str_trim_ctr(char *str, char **trim, ud_bool need_free);
void                                ud_str_rtrim_ctr(char **str, size_t depth, char **trim);

#endif