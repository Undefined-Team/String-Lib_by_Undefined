#include <ud_string.h>
#include <ud_array.h>
#include <assert.h>

int main(void)
{
    // char *a = "a";
    // char *abc = "abc";
    // char *de = "de";
    // char *aaaaa = "aaaaa";
    // char *abcde = "abcde";
    // char *abzde = "abzde";
    // char *abade = "abade";
    // char *null = NULL;

    // ud_ut_time("%s", "Starting tests...");
    // // Basic tests
    // assert(ud_str_cmp(abade, abzde) == 'a' - 'z');
    // assert(ud_str_cmp(abcde, abcde) == 0);
    // assert(ud_str_cmp(null, abcde) == -1);
    // assert(ud_str_cmp(ud_str_dup(abcde), abcde) == 0);
    // assert(ud_str_chr(null, 'a') == -1);
    // assert(ud_str_chr(abcde, 'a') == 0);
    // assert(ud_str_chr(abcde, 'c') == 2);
    // assert(ud_str_chr(abcde, 'f') == -1);
    // assert(!ud_str_cmp(ud_str_fill('a', 5), aaaaa));
    // assert(!ud_str_cmp(ud_str_join(abc, de), abcde));
    // assert(!ud_str_cmp(ud_str_sub(abcde, 0, 3), abc));
    // assert(!ud_str_cmp(ud_str_sub(abcde, 3, 2), de));
    // assert(!ud_str_cmp(ud_str_ctoa('a'), a));
    // ud_ut_time("%s", "All tests passed.");

    // printf("%zd\n", UD_ARGS_LEN(int, 1, 2, 3));
    // return 0;
    // char value[] = ",,2,";
    // ud_arr  *str = ud_arr_new(sizeof(char), 4, value);
    // ud_arr_print(str, char, "%c");
    // ud_arr  *splitted = ud_str_split(str, ",");
    // printf("splitted len = %zd\n", splitted->len);
    // ud_arr *before_test =  ud_arr_init(sizeof(char), 0);
    // printf("splitted:\n");
    // ud_arr_print(splitted, char, "|%c| ");
    // printf("before_test:\n");
    // ud_arr_print(before_test, char, "|%c| ");
    // ud_arr *test = ud_arr_init(0, 2);
    // printf("add real = %p\n", splitted);
    // printf("auto:\n");
    // ud_arr *test = ud_arr_set(ud_arr*, splitted, before_test);
    // printf("auto len = %zd\n", test->len);
    // ud_arr **val = (ud_arr**)test->val;
    // printf("elemt1 len = %zd\n", val[0]->len);
    // ud_arr_print(val[0], char, "|%c| ");

    // ud_arr_print(test, char, "|%c| ");
    // ud_arr_rfree(test);

    // test = ud_arr_init(0, 2);
    // ud_arr **val = (ud_arr**)test->val;
    // val[0] = before_test;
    // val[1] = splitted;
    // printf("manual:\n");
    // ud_arr_print(test, char, "|%c| ");
    // ud_arr_rfree(test);
    // ud_arr *test_set = ud_arr_set(int, 2, 3);
    // ud_arr_print(test_set, int, "%d ");
    // ud_arr_free(str);

    char test[] = "JOHNY,salutJOHNY, caJOHNY, vaJOHNY,";
    char **splitted = ud_str_split(test, "JOHNY,");
    char **begin = splitted;
    while (*splitted)
    {
        printf("split = |%s|\n", *splitted);
        ud_ut_free(*splitted);
        ++splitted;
    }
    ud_ut_free(begin);
    return 0;
}