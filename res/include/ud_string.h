#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <ud_utils.h>
#include <ud_array.h>

// Macro
# define                        ud_str_is_white_space(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\v' || (c) == '\f' || (c) == '\0')

// Structures
typedef struct                  uds_str_split_len {
    size_t                      len;
    struct uds_str_split_len    *next;
}                               ud_str_split_len;        

// Prototypes
int                             ud_str_chr(ud_arr *str, char c);
int                             ud_str_cmp(ud_arr *s1, ud_arr *s2);
ud_arr                          *ud_str_ctoa(char c);
ud_arr                          *ud_str_dup(ud_arr *str, size_t len);
ud_arr                          *ud_str_fdup(ud_arr *str, size_t len);
ud_arr                          *ud_str_fill(char c, size_t len);
ud_arr                          *ud_str_fjoin(ud_arr *head, ud_arr *tail);
ud_arr                          *ud_str_fsub(ud_arr *str, size_t start, size_t len);
ud_arr                          *ud_str_join(ud_arr *head, ud_arr *tail);
ud_arr                          *ud_str_sub(ud_arr *str, size_t start, size_t len);
size_t                          ud_str_len(ud_arr *str);
ud_arr                          *ud_str_split(ud_arr *str, char *sep);

#endif