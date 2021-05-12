#include <algorithm>

#include "boyer_moore.h"
#include "utils.h"

int BoyerMoore(std::string txt, std::string pat)  {
  std::vector<int> bad = BadChar(pat);
	std::vector<int> good = GoodSuffix(pat);
  int n = txt.size(), m = pat.size();
  int i = 0, j, occ = 0;

  while (i <= n - m) {
    j = m - 1;
    while (j >= 0 && txt[i+j] == pat[j]) j--;
    if (j < 0) { occ++; i++; }
    else i += std::min(m, std::max(j - bad[int(txt[i+j])], good[j]));
  }

  return occ;
}

std::vector<int> BadChar(std::string pat) {
  int m = pat.size();
  std::vector<int> tab(ALPHABET_SIZE, -1);

  for (int i = 0; i < m; i++) {
    tab[int(pat[i])] = i;
  }

  return tab;
}

std::vector<int> GoodSuffix(std::string pat) {
	int m = pat.size();
	std::vector<int> pi = borders(pat);
  std::vector<int> tab(m, m - pi[m]);

	std::reverse(pat.begin(), pat.end());
	std::vector<int> pi_rev = borders(pat);

  for (int i = 1, j; i < m; i++) {
    j = m - 1 - pi_rev[i];
    if (i - pi_rev[i] < tab[j]) {
      tab[j] = i - pi_rev[i];
    }
  }

	return tab;
}
