#include"x.h"
class Solution_139 {
public:
	bool wordBreak(string s, vector<string>&wordDict) {
		const int n = s.size();
		vector<bool>f(n + 1, false);
		f[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};