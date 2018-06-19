#include"x.h"


//看不懂
class Solution_91 {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int prev = 0;
		int cur = 1;
		// 长度为n的字符串，有 n+1 个阶梯
		for (size_t i = 1; i <= s.size(); ++i) {
			if (s[i - 1] == '0') cur = 0;
			if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
				prev = 0;

			int tmp = cur;
			cur = prev + cur;
			prev = tmp;
		}

		return cur;
	}
};

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}
};