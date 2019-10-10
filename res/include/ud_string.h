#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define ud_str_is_white_space(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\v' || (c) == '\f' || (c) == '\0')
# define ud_str_dup(str)            (ud_str_ndup(str, 0))
# define ud_str_fdup(str)           (ud_str_fndup(str, 0))

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
size_t                              ud_str_len(char *str);
char                                *ud_str_escape(char *str);
char                                *ud_str_whitespace(char *str);

#endif