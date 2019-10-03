#include <ud_string.h>
#include <ud_array.h>
#include <assert.h>

int main(void)
{
    ud_arr *a = ud_arr_set(char, 1, 'a');
    ud_arr *abc = ud_arr_set(char, 3, 'a', 'b', 'c');
    ud_arr *de = ud_arr_set(char, 2, 'd', 'e');
    ud_arr *aaaaa = ud_arr_set(char, 5, 'a', 'a', 'a', 'a', 'a');
    ud_arr *abcde = ud_arr_set(char, 5, 'a', 'b', 'c', 'd', 'e');
    ud_arr *abzde = ud_arr_set(char, 5, 'a', 'b', 'z', 'd', 'e');
    ud_arr *abade = ud_arr_set(char, 5, 'a', 'b', 'a', 'd', 'e');
    ud_arr *null = ud_arr_set(char, 1, 'a');
    null->val = NULL;
    null->len = 0;

    ud_ut_time("%s", "Starting tests...");
    // Basic tests
    assert(ud_str_cmp(abade, abzde) == 'a' - 'z');
    assert(ud_str_cmp(abcde, abcde) == 0);
    assert(ud_str_cmp(null, abcde) == -1);
    assert(ud_str_cmp(ud_str_dup(abcde, abcde->len), abcde) == 0);
    assert(ud_str_chr(null, 'a') == -1);
    assert(ud_str_chr(abcde, 'a') == 0);
    assert(ud_str_chr(abcde, 'c') == 2);
    assert(ud_str_chr(abcde, 'f') == -1);
    assert(!ud_str_cmp(ud_str_fill('a', 5), aaaaa));
    assert(!ud_str_cmp(ud_str_join(abc, de), abcde));
    assert(!ud_str_cmp(ud_str_sub(abcde, 0, 3), abc));
    assert(!ud_str_cmp(ud_str_sub(abcde, 3, 2), de));
    assert(!ud_str_cmp(ud_str_ctoa('a'), a));
    ud_ut_time("%s", "All tests passed.");
}