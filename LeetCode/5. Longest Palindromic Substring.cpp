#include"x.h"

//最长回文串：字符串反转后相同，如“abcba”
//动态规划，利用上一步 j到i 之间的字符串是否是回文串:if f[j][i]==true?
//每步只需左右扩展一步，即比较s[j] == s[i]，且上一步为真(为回文串)，则这一步是回文串，true
class Solution_5_1 {
public:
	string longestPalindrome(string s) {
		const int n = s.size();
		//bool f[n][n];
		//fill_n(&f[0][0], n * n, false);
		// 用 vector 
		vector<vector<bool> > f(n, vector<bool>(n, false));
		size_t max_len = 1, start = 0; // 最长回文子串的长度，起点
		for (size_t i = 0; i < s.size(); i++) {
			f[i][i] = true;
			for (size_t j = 0; j < i; j++) { // [j, i]
				f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
				if (f[j][i] && max_len < (i - j + 1)) {
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};


//从中心往外探索
class Solution_5_2 {
public:
	string longestPalindrome(string s) {
		int n = s.size(), len = 0, start = 0;
		for (int i = 0; i != n; ++i) {
			int left = i, right = i;
			while (right < n - 1 && s[right] == s[right + 1])++right;
			while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
				--left;
				++right;
			}
			if (len < right - left + 1) {
				len = right - left + 1;
				start = left;
			}
		}
		return s.substr(start, len);
	}
};