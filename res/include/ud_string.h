#ifndef UD_STRING_H
# define UD_STRING_H

// Lib
#include <ud_utils.h>
#include <ud_array.h>

// Macro

// Structures

// Prototypes
int         ud_str_chr(ud_arr *str, char c);
int         ud_str_cmp(ud_arr *s1, ud_arr *s2);
ud_arr      *ud_str_ctoa(char c);
ud_arr      *ud_str_dup(ud_arr *str, size_t len);
ud_arr      *ud_str_fdup(ud_arr *str, size_t len);
ud_arr      *ud_str_fill(char c, size_t len);
ud_arr      *ud_str_fjoin(ud_arr *head, ud_arr *tail);
ud_arr      *ud_str_fsub(ud_arr *str, size_t start, size_t len);
ud_arr      *ud_str_join(ud_arr *head, ud_arr *tail);
ud_arr      *ud_str_sub(ud_arr *str, size_t start, size_t len);

#endif