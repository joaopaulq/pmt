#ifndef KMP_H_
#define KMP_H_

#include <string>

// Compues the number of occurrences of a given pattern
// in a given text using the Knuth-Morris-Pratt algorithm.
int KMP(std::string txt, std::string pat);

#endif
