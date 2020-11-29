#ifndef BOYER_MOORE_H_
#define BOYER_MOORE_H_

#include <string>
#include <vector>

// Compues the number of occurrences of a given pattern
// in a given text using the Boyer-Moore algorithm.
int BoyerMoore(std::string txt, std::string pat);

// Returns the position of the last occurrence of each
// character in the alphabet in the given pattern.
std::vector<int> BadChar(std::string pat);

// Returns for each position, in the given pattern, the
// size of the largest prefix which is also a suffix in
// the  substring starting in that position down to 0.
std::vector<int> GoodSuffix(std::string pat);

#endif
