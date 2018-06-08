#include"x.h"

class Solution_10_1 {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}
private:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') return *s == '\0';
		// next char is not '*', then must match current character
		if (*(p + 1) != '*') {
			if (*p == *s || (*p == '.' && *s != '\0'))
				return isMatch(s + 1, p + 1);
			else
				return false;
		}
		else { // next char is '*'
			while (*p == *s || (*p == '.' && *s != '\0')) {
				if (isMatch(s, p + 2))
					return true;
				s++;
			}
			return isMatch(s, p + 2);
		}
	}
};