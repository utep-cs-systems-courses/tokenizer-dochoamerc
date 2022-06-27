#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/*
    The following is a simple testing script with a single example of input
    your code is expected to handle. The testing of your code should be more
    thorough and explore other input cases.
*/

#define TEST_TOKENIZER 1
#define TEST_HISTORY 1

/* MinUnit: http://www.jera.com/techinfo/jtns/jtn002.html */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)
int tests_run;
/* end MinUnit */


/* Tokenizer test cases */
static char *test_non_space_char() {
    mu_assert("is_non_space_char(' ') == 0", non_space_char(' ') == 0);
    mu_assert("is_non_space_char('h') == 1", non_space_char('h') == 1);
    return 0;
}

static char *test_find_word_start() {
  char *str = "  happy", *empty="", *str2="happy happy joy", *str3="    ";
    mu_assert("word_start('  happy') == &str[2]'", word_start(str) == &str[2]);
    mu_assert("word_start(emptyStr) == empty", word_start(empty) == NULL);
    mu_assert("word_start('happy happy joy') == &str2[0]", word_start(str2) == &str2[0]);
    mu_assert("word_start('    ') == NULL", word_start(str3) == NULL);
    return 0;
}

static char *test_find_word_terminator() {
  char *str = "happy joy", *empty="", *str2="  happy test", *str3 = "  happy";
    mu_assert("word_terminator('happy joy') == &str[5]'", word_terminator(str) == &str[5]);
    mu_assert("word_terminator(emptyStr) == empty", word_terminator(empty) == empty);
    mu_assert("word_terminator('  happy test') == &str2[7]", word_terminator(str2) == &str2[7]);
    mu_assert("word_terminator('  happy') == 0", word_terminator(str3) == 0);
    return 0;
}

static char *test_count_words() {
  char *str = "happy happy joy joy", *str2 = "test", *str3 = "  test 1", *str4 = "test 1  ", *copy;
  mu_assert("count_words('happy happy joy joy') == 4", count_words(str) == 4);
  mu_assert("count_words('test') == 1", count_words(str2) == 1);
  mu_assert("count_words('  test 1') == 2", count_words(str3) == 2);
  mu_assert("Copy str = 'happy happy joy joy'", *(copy = copy_str(str,19)) == *str);
  return 0;
}

static char *test_tokenize() {
    char *str = "happy happy joy joy";
    char **tokens = tokenize(str);
    mu_assert("tokens[0] == 'happy'", strcmp(tokens[0], "happy") == 0);
    mu_assert("tokens[1] == 'happy'", strcmp(tokens[1], "happy") == 0);
    mu_assert("tokens[2] == 'joy'", strcmp(tokens[2], "joy") == 0);
    mu_assert("tokens[3] == 'joy'", strcmp(tokens[3], "joy") == 0);
    print_tokens(tokens);
    free_tokens(tokens);
    return 0;
}

/* History test cases */

static char *test_add_history() {
    List* list = init_history();
    add_history(list, "happy");
    mu_assert("add_history(list, 'happy')", strcmp(list->root->str, "happy") == 0);
    add_history(list, "joy");
    mu_assert("add_history(list, 'joy')", strcmp(list->root->next->str, "joy") == 0);
    return 0;
}

static char *test_get_history() {
    List* list = init_history();
    add_history(list, "happy");
    add_history(list, "joy");
    mu_assert("get_history(list, 1)", strcmp(get_history(list, 1), "happy") == 0);
    mu_assert("get_history(list, 2)", strcmp(get_history(list, 2), "joy") == 0);
    //print_history(list);
    free_history(list);
    return 0;
}


static char *all_tests() {
  if (TEST_TOKENIZER) {
        mu_run_test(test_non_space_char);
        mu_run_test(test_find_word_start);
        mu_run_test(test_find_word_terminator);
	mu_run_test(test_count_words);
	mu_run_test(test_tokenize);
    }
 
  if (TEST_HISTORY) {
      mu_run_test(test_add_history);
      mu_run_test(test_get_history);
  }

  return 0;
}

 int main(int argc, char **argv) {   
    char *result = all_tests();

    if (result != 0) 
        printf("Failed test: %s\n", result);
    else 
        printf("ALL TESTS PASSED\n");
    
    printf("Tests run: %d\n", tests_run);

    return result != 0;
 }
