#include <ud_string.h>
#include <assert.h>

# define nameof(var)    #var

char*    print_state(void *ptr)
{
    if (ptr <= (void*)&ptr) ud_str_dup("malloc\n");
    else ud_str_dup("static\n");
    return NULL;
}

void ud_str_test_tmp(void)
{
    char *a = "a";
    char *b = "b";
    char *abc = "abc";
    char *def = "def";
    char *abcdef = ud_str_dup("abcdef");
    char *aaaaaa = ud_str_dup("aaaaaa");

    ud_ut_test(ud_str_chr(abc, 'a') == 0);
    ud_ut_test(ud_str_chr(abc, 'b') == 1);
    ud_ut_test(ud_str_chr(abc, 'c') == 2);
    ud_ut_test(ud_str_chr(abc, 0) == -1);
    ud_ut_test(ud_str_chr(abc, 'd') == -1);
    ud_ut_test(a != ud_str_dup(a));
    ud_ut_test(!ud_str_cmp(a, ud_str_dup(a)) == !ud_mem_cmp(a, ud_str_dup(a), 2) && !ud_str_cmp(a, ud_str_dup(a)));
    ud_ut_test(!ud_str_cmp(a, ud_str_dup("a")));
    ud_ut_test(ud_str_dup(NULL) == NULL);
    ud_ut_test(!ud_str_cmp(NULL, NULL));
    ud_ut_test(ud_str_cmp(a, b) == -1);
    ud_ut_test(ud_str_cmp(b, a) == 1);
    ud_ut_test(ud_str_cmp(a, abc) < 0);
    ud_ut_test(ud_str_cmp(abc, a) > 0);
    ud_ut_test(ud_str_cmp(NULL, abc) < 0);
    ud_ut_test(ud_str_cmp(abc, NULL) > 0);
    ud_ut_test(!ud_str_cmp(abc, "abc"));
    ud_ut_test(!ud_str_ncmp(abc, a, 1));
    ud_ut_test(!ud_str_ncmp(a, abc, 1));
    ud_ut_test(!ud_str_ncmp(abcdef, abc, 3));
    ud_ut_test(!ud_str_ncmp(abcdef, a, 1));
    ud_ut_test(ud_str_ncmp(NULL, NULL, 0) == 0);
    ud_ut_test(!ud_str_cmp("a", ud_str_ctoa('a')));
    ud_ut_test(!ud_str_cmp("", ud_str_ctoa(0)));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(abcdef, 3), abc));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(abcdef, 4), "abcd"));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(abcdef, 1000), abcdef));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(abcdef, 0), abcdef));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(NULL, 0), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_ndup(NULL, 100), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_fill('a', 6), aaaaaa));
    ud_ut_test(!ud_str_cmp(ud_str_fill('0', 6), "000000"));
    ud_ut_test(!ud_str_cmp(ud_str_fill(0, 0), ""));
    ud_ut_test(!ud_mem_cmp(ud_str_fill(0, 6), "\0\0\0\0\0\0", 6));
    ud_ut_test(!ud_str_cmp(ud_str_cat(abc, def), abcdef));
    ud_ut_test(!ud_str_cmp(ud_str_cat(NULL, abc), abc));
    ud_ut_test(!ud_str_cmp(ud_str_cat(abc, NULL), abc));
    ud_ut_test(ud_str_cat(NULL, NULL) == NULL);
    ud_ut_test(!ud_str_cmp(ud_str_sub(abcdef, 0, 3), abc));
    ud_ut_test(!ud_str_cmp(ud_str_sub(abcdef, 3, 6), def));
    ud_ut_test(!ud_str_cmp(ud_str_sub(abcdef, 3, 100), def));
    ud_ut_test(!ud_str_cmp(ud_str_sub(abcdef, 3, 0), ""));
    ud_ut_test(!ud_str_cmp(ud_str_sub(abcdef, 10, 10), ""));
    ud_ut_test(ud_str_sub(NULL, 0, 1000) == NULL);
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "a", "b", "c", "d", "e", "f"), ","), "a,b,c,d,e,f"));
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "a", "b", "c", "d", "e", "f"), NULL), "abcdef"));
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "a"), NULL), "a"));
    ud_ut_test(!ud_str_cmp(ud_str_join(NULL, ","), ""));
    ud_ut_test(!ud_str_cmp(ud_str_join(NULL, NULL), ""));
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "a", "b", "c", "d", "e", "f"), ","), "a,b,c,d,e,f"));
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "a", "b", "c", "d", "e", "f"), "FOO"), "aFOObFOOcFOOdFOOeFOOf"));
    ud_ut_test(!ud_str_cmp(ud_str_join(ud_ut_array(char *, "FOO", "FOO"), "FOO"), "FOOFOOFOO"));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin(",", "a", "b", "c", "d"), "a,b,c,d"));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin(",", NULL), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin("FOO", "FOO", "FOO"), "FOOFOOFOO"));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin(",", NULL, NULL, NULL), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin(NULL, "a", "b", "c", "d"), "abcd"));
    ud_ut_test(!ud_str_cmp(ud_str_vjoin(NULL, NULL, NULL), NULL));
    ud_ut_test(ud_str_len(NULL) == 0);
    ud_ut_test(ud_str_len("a") == 1);
    ud_ut_test(ud_str_len("a\0\0") == 1);
    ud_ut_test(ud_str_len("abcdefghijklmnopqrstuvwxyz") == 26);
    ud_ut_test(ud_str_len("") == 0);
    ud_ut_test(!ud_str_cmp(ud_str_escape("foo"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"foo\""), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"\""), ""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"\"\"\""), "\"\""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'foo\'"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'\'"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'\'\'\'"), "\'\'"));
    ud_ut_test(!ud_str_cmp(ud_str_escape(NULL), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_escape(""), ""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"foo"), "\"foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\""), "\""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"\"foo\""), "\"foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\"\"\""), "\""));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'foo"), "\'foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'"), "\'"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'\'foo\'"), "\'foo"));
    ud_ut_test(!ud_str_cmp(ud_str_escape("\'\'\'"), "\'"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("foo"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\nfoo\n"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\n\n"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\n\n\n\n"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\tfoo\t"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\t\t"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\t\t\t\t"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace(NULL), NULL));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace(""), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\nfoo"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\n"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\n\nfoo\n"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\n\n\n"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\tfoo"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\t"), ""));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\t\tfoo\t"), "foo"));
    ud_ut_test(!ud_str_cmp(ud_str_whitespace("\t\t\t"), ""));
    
    ud_str_cpy(abcdef, aaaaaa);
    ud_str_cpy(abc, NULL); // test segfault
    ud_str_cpy(NULL, abc); // test segfault

    ud_ut_test(!ud_str_cmp(abcdef, aaaaaa));

    char *split = "aFOObFOOcdcdecFOOdwqdFOFOOFO";
    char **splitted = ud_str_split(split, "FOO");
    char **splitted_verif = ud_ut_array(char *, "a", "b", "cdcdec", "dwqdFO", "FO");
    char **splitted2 = ud_str_split("abc", " ");

    for (ud_ut_count i = 0; i < 5; ++i)
        ud_ut_dtest(!ud_str_cmp(splitted[i], splitted_verif[i]), "[%zu] %s %s", i, splitted[i], splitted_verif[i]);
    ud_ut_test(ud_str_split(NULL, "a") == NULL);
    ud_ut_test(ud_ptr_len(splitted2) == 1);
    ud_ut_test(!ud_str_cmp(splitted2[0], abc));
    ud_ut_test(1 && ud_str_split("abc", NULL)); // should exit with ud_ut_error

    // split sep = "" split chaque char

}

int main(void)
{
    char *split2 = "abc";
    char **splitted2 = ud_str_split(split2 , "");
    printf("LAUNCH %zd\n", ud_ptr_len(splitted2));
    ud_ptr_foreach(splitted2, elem, printf("TEST = %s\n", *elem););
    printf("%s\n", ud_str_join(splitted2, NULL));
    return 0;
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

    // Test split (0 leak)
    // char test[] = "JOHNY,salutJOHNY, caJOHNY, vaJOHNY,";
    // char **splitted = ud_str_split(test, "JOHNY,");
    // char **begin = splitted;
    // printf("split = ");
    // while (*splitted)
    // {
    //     printf("[%s], ", *splitted);
    //     ud_ut_free(*splitted);
    //     ++splitted;
    // }
    // printf("\n");
    // ud_ut_free(begin);

    // Test join with va_args (0 leak)
    // char *vjoined = ud_str_vjoin("-", "salut", "cava");
    // printf("vjoin = |%s|\n", vjoined);
    // ud_ut_free(vjoined);

    // Test join with static and without free (little leak)
    // char *mt1[3] = {"oui" , "non", NULL};
    // char *mt2[3] = {"si", "peut etre", NULL};
    // char **main_test[3] = {mt1, mt2, NULL};
    // char *joinedr = ud_str_vrjoin(main_test, " ; ", ", ");
    // printf("vrjoin = |%s|\n", joinedr);
    // ud_ut_free(joinedr);

    // Test join with malloc (0 leak)
    // char **mt1f = ud_ptr_set(char*, ud_str_dup("oui"), ud_str_dup("non"), NULL);
    // char **mt2f = ud_ptr_set(char*, ud_str_dup("si"), ud_str_dup("peut etre"), NULL);
    // char ***main_testf = ud_ptr_set(char**, mt1f, mt2f, NULL);

    // char *test_str = ud_str_dup("ouicaca, non ; si, peut etre");
    // char **main_testf = ud_str_vrsplit(test_str, " ; ", ", ");
    // ud_ut_free(test_str);
    // ud_str_vrtrim(main_testf,1, "ca");
    // printf("vrsplit end %s\n", **(char***)main_testf);

    // char *joinedrf = ud_str_vrjoin(main_testf, " ; ", ", ");
    // printf("vrsplit end %s\n", **(char***)main_testf);

    // ud_ptr_free(main_testf,2);

    // printf("vrfjoin = |%s|\n", joinedrf);
    // ud_ut_free(joinedrf);
    
    // char **trimer = ud_ut_array(char*, "salut", "caca", NULL);
    // char *trimed = ud_str_trim("salutcacaca", trimer);
    // printf("trimed |%s|\n", trimed);
    // ud_ut_free(trimer);
    // ud_ut_free(trimed);

    // int is_st[] = {1};
    // int *is_st1 = is_st; 
    // int *is_ma = malloc(sizeof(int));
    // int *is_ma1 = is_st1;

    // int is_st2[] = {1, 2};
    // int *is_ma2 = malloc(sizeof(int) * 2);

    // printf("%p %p %p\n", is_st, is_st1, is_ma);
    // printf("%p %p %p\n", &is_st, &is_st1, &is_ma);
    // printf("%d %d %d\n", is_st, is_st1, is_ma);
    // printf("%d %d %d\n", &is_st, &is_st1, &is_ma);
    // printf("%zd %zd\n", sizeof(is_st2), sizeof(is_ma2));
    // printf("%d %d\n", typeof(is_st2) == typeof(is_ma2), typeof(is_st) == typeof(is_st2));
    
    // printf("%s = %s", nameof(is_st), print_state(is_st));
    // printf("%s = %s", nameof(is_st1), print_state(is_st1));
    // printf("%s = %s", nameof(is_st2), print_state(is_st2));
    // printf("%s = %s", nameof(is_ma), print_state(is_ma));
    // printf("%s = %s", nameof(is_ma1), print_state(is_ma1));
    // printf("%s = %s", nameof(is_ma2), print_state(is_ma2));
    ud_str_test_tmp();
    return 0;
}