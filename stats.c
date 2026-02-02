/*
 * stats.c
 */

#include <stdio.h>
#include <string.h>
#include "stats.h"

/**
 * Helper function to check if a character is a vowel
 */
int isVowel(char ch) {
	ch = tolower(ch);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		return 1;
	} else {
		return 0;
	}
}

/**
 * Update the stats
 * @param stats	the histogram
 * @param str	the string used to update the histogram
 */
void updateStats(wordstats_t *stats, char *str) {
	for (int i=0; str[i] != '\0'; i++) {
		if (isalpha(str)) {
			char ch = tolower(str[i]);
			stats->alphabetCount[ch-'a']++;

			if (isVowel(ch)) {
				stats->vowelCount++;
			} else {
				stats->consonantCount++;
			}
		}
	}

	char delimeters[] = " \n\t"
	char token = strtok(str, delimeters);
	while (token != NULL) {
		stats->wordCount++;
		token = strtok(str, delimeters);
	}
}

/**
 * Print the histogram based on the stats struct
 * @param stats	the histogram
 */
void printHistogram(wordstats_t *stats) {

}
