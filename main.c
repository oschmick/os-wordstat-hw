/*
 * main.c
 * @author Olivia Schmick
 */
#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128	/** maximum allowed input length */
#define STOP_CHAR = '#'

void getStrings(char *input[]) {
	printf("Enter strings (%c to stop): \n", STOP_CHAR);
	while (1) {
		int len = strlen(fgets(input, sizeof(input), stdin));
		if (len == 2 && input[0] == '#') {
			break;
		}

	}
}

/**
 * @brief Main function
 */
int main(int argc, char *argv[]) {
	struct wordstats_t stats = {0,0,0,{0}};
	char input[MAX_INPUT_LEN];
	int choice;

	getStrings(&input);

	while (1) {
		printMenu();
		scanf("%d", &choice);

		if (choice == 1) {
			// TODO
		} else if (choice == 2) {
			// TODO
		} else if (choice == 3) {
			getStrings(&input);
		} else {
			break;
		}
	}

	printf("Exiting...\n");
	return 0;
}
