#include <fstream>
#include <iterator>
#include <algorithm>

#include "utils.h"

std::string to_string(std::string path) {
	return std::string(
		(std::istreambuf_iterator<char>(std::ifstream(path))),
		std::istreambuf_iterator<char>()
	);
}

std::vector<int> Borders(std::string pat) {
  int m = pat.size();
  std::vector<int> brd(m+1, 0);
  brd[0] = -1;
  int i = 1, j = 0;

  while (i < m) {
    while (j < m && i+j < m && pat[i+j] == pat[j]) {
			brd[i+j] = ++j;
		}
    i += std::max(1, j - brd[j]);
    j = std::max(0, brd[j]);
  }

  return brd;
}

#endif
