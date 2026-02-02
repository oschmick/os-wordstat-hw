/*
 * stats.h
 */

#ifndef STATS_H_
#define STATS_H_

// TODO word stats constants
#define ALPHABET_LEN 26

// TODO word stats struct
typedef struct {
    int vowelCount;
    int consonantCount;
    int wordCount;
    int alphabetCount[ALPHABET_LEN];
} wordstats_t;

// TODO functions declarations
void updateStats(wordstats_t *stats, char *str);
void printFrequencies(wordstats_t *stats);
void printHistogram(wordstats_t *stats);

#endif /* STATS_H_ */
