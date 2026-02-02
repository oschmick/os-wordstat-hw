/*
 * main.c
 * @author Olivia Schmick
 */
#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128	/** maximum allowed input length */
#define STOP_CHAR '#'

void getStrings(wordstats_t *stats, char *input, int inputSize);

/**
 * @brief Main function
 */
int main(int argc, char *argv[]) {
	wordstats_t stats = {0,0,0,{0}};
	char input[MAX_INPUT_LEN];
	int choice;

	getStrings(&stats, input, MAX_INPUT_LEN);

	while (1) {
		printMenu();
		if (scanf("%d", &choice) != 1) {
			break;
		}

		if (choice == 1) {
			printFrequencies(&stats);
		} else if (choice == 2) {
			printHistogram(&stats);
		} else if (choice == 3) {
			getStrings(&stats, input, MAX_INPUT_LEN);
		} else {
			break;
		}
	}

	printf("Exiting...\n");
	return 0;
}

void getStrings(wordstats_t *stats, char *input, int inputSize) {
	printf("Enter strings (# to stop): \n");
	while (1) {
		if (fgets(input, inputSize, stdin) == NULL) {
			break;
		}
		if (input[0] == '#') {
			break;
		}
		if (input[0] != '\0') {
			updateStats(stats, input);
		}
	}
}