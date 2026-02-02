/*
 * stats.h
 */

#ifndef STATS_H_
#define STATS_H_

// TODO word stats constants

// TODO word stats struct
struct wordstats_t {
    int vowelCount;
    int consonantCount;
    int wordCount;
    int alphabetCount[26];
}

// TODO functions declarations
void updateStats(wordstats_t *stats, char *str);
void printHistogram(wordstats_t *stats);

#endif /* STATS_H_ */
