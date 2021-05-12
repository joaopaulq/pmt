#include <vector>
#include <algorithm>

#include "utils.h"
#include "kmp.h"

int KMP(std::string txt, std::string pat)  {
  int n = txt.size(), m = pat.size(), occ = 0;
  std::vector<int> brd = borders(pat);

  int i = 0, j = 0;
  while (i <= n - m) {
    while (j < m && txt[i+j] == pat[j]) j++;
    if (j == m) occ++;
    i += std::max(1, j - brd[j]);
    j = std::max(0, brd[j]);
  }

  return occ;
}
