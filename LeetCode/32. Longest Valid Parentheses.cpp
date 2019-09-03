#include"x.h"

class Solution_32_1 {
public:
	int longestValidParentheses(const string& s) {
		int max_len = 0, last = -1; // the position of the last ')'
		stack<int> lefts; // keep track of the positions of non-matching '('s
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				lefts.push(i);
			}
			else {
				if (lefts.empty()) {
					// no matching left
					last = i;
				}
				else {
					// find a matching pair
					lefts.pop();
					if (lefts.empty()) {
						max_len = max(max_len, i - last);
					}
					else {
						max_len = max(max_len, i - lefts.top());
					}
				}
			}
		}
		return max_len;
	}
};


//Dynamic Programming, One Pass
class Solution_32_2 {
public:
	int longestValidParentheses(const string& s) {
		vector<int> f(s.size(), 0);
		int ret = 0;
		for (int i = s.size() - 2; i >= 0; --i) {
			int match = i + f[i + 1] + 1;
			// case: "((...))"
			if (s[i] == '(' && match < s.size() && s[match] == ')') {
				f[i] = f[i + 1] + 2;
				// if a valid sequence exist afterwards "((...))()"
				if (match + 1 < s.size()) f[i] += f[match + 1];
			}
			ret = max(ret, f[i]);
		}
		return ret;
	}
};



class Solution_32_3 {
public:
	int longestValidParentheses(const string& s) {
		int answer = 0, depth = 0, start = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				++depth;
			}
			else {
				--depth;
				if (depth < 0) {
					start = i;
					depth = 0;
				}
				else if (depth == 0) {
					answer = max(answer, i - start);
				}
			}
		}
		depth = 0;
		start = s.size();
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == ')') {
				++depth;
			}
			else {
				--depth;
				if (depth < 0) {
					start = i;
					depth = 0;
				}
				else if (depth == 0) {
					answer = max(answer, start - i);
				}
			}
		}
		return answer;
	}
};