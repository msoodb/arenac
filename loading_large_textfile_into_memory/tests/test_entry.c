#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "entry.h"

START_TEST(test_load_entry) {
	int length = 0;
	char **words;

	char *filename = malloc(sizeof(char) * 33);
	strcpy(filename, "tests/test_load_entry_data_1.txt");

	words = load_entry(filename, &length);
	ck_assert_pstr_ne(*words, NULL);
	ck_assert_int_eq(length, 466550);

	/* clean allocated memory */
	if (words != NULL) {
		int i;
		for (i=0; i < length; ++i) {
			free(* (words + i));
		}
		free(words);
	}
	printf(" [PASS] Test: tests/test_load_entry_data_1.txt \n");
} END_TEST

Suite *calc_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("entry_test");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_load_entry);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	Suite *s = calc_suite();
	SRunner *runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	int no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
