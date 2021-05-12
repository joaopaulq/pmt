#include <vector>
#include <algorithm>

#include "sellers.h"

int Sellers(std::string a, std::string b, int e_max) {
	int n = a.size(), m = b.size(), occ = 0;
	std::vector<std::vector<int> > dp(2, std::vector<int>(n+1, 0));
	bool cur = 1;

	for (int i = 1; i <= m; i++) {
		dp[cur][0] = i;
  	for (int j = 1; j <= n; j++) {
	    dp[cur][j] = std::min(
				std::min(dp[!cur][j], dp[cur][j-1]) + 1,
	    	dp[!cur][j-1] + phi(b[i-1], a[j-1])
			);
	    if (i == m && dp[cur][j] <= e_max) occ++;
	  }
	  cur = !cur;
	}

	return occ;
}

bool phi(unsigned char a, unsigned char b) {
	return a != b;
}
