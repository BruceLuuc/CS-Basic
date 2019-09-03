#include"x.h"

class Solution_718_1 {
public:
	int longestCommonSubstring(string &A, string &B) {
		// write your code here
		const int m = A.size();
		const int n = B.size();
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
		int res = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (A[i - 1] == B[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 0;
				res = max(res, dp[i][j]);
			}
		return res;
	}
};