/*
 * stats.c
 */

#include <ctype.h>
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
		if (isalpha(str[i])) {
			char ch = tolower(str[i]);
			stats->alphabetCount[ch-'a']++;

			if (isVowel(ch)) {
				stats->vowelCount++;
			} else {
				stats->consonantCount++;
			}
		}
	}

	const char delimeters[] = " \n\t";
	char *token = strtok(str, delimeters);
	while (token != NULL) {
		stats->wordCount++;
		token = strtok(NULL, delimeters);
	}
}

/**
 * Print the frequency statistics based on the stats struct
 * @param stats	the histogram
 */
void printFrequencies(wordstats_t *stats) {
	double numWords = stats->wordCount;
	double numVowels = stats->vowelCount;
	double numConsonants = stats->consonantCount;
	double total = numVowels + numConsonants;
	double percentVowels = (numVowels/total)*100;
	double percentConsonants = (numConsonants/total)*100;
	double avgWordLen = total/numWords;

	printf("\nWords = %.0lf, Average Word Length = %.2lf\n", numWords, avgWordLen);
	printf("Vowels = %.0lf (%.2lf%%), Consonants = %.0lf (%.2lf%%), Total = %.0lf\n\n", numVowels, percentVowels, numConsonants, percentConsonants, total);
}

/**
 * Print the histogram based on the stats struct
 * @param stats	the histogram
 */
void printHistogram(wordstats_t *stats) {
	int max = 0;
	int *alphabet = stats->alphabetCount;
	int length = sizeof(stats->alphabetCount)/sizeof(alphabet[0]);

	for (int i=0; i<length; i++) {
		int letter = alphabet[i];
		if (letter > max) {
			max = letter;
		}
	}

	for (int i=max; i>0; i--) {
		for (int j=0; j<length; j++) {
			if (alphabet[j] >= i) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}

	printf("a b c d e f g h i j k l m n o p q r s t u v w x y z \n");

	for (int i=0; i<length; i++) {
		printf("%d ", alphabet[i]);
	}

	printf("\n\n");
}
