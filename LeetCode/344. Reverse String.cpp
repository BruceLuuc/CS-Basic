#include"x.h"


//太简单了  不值得记录
class Solution_344_1 {
public:
	string reverseString(string s) {
		const int n = s.size();
		if (n<2)return s;

		string tmp;

		for (int i = n - 1; i >= 0; i--) {
			tmp += s[i];
		}
		return tmp;

	}
};

class Solution_344_2 {
public:
	string reverseString(string s) {
		const int n = s.size();
		if (n<2)return s;

		int left = 0;
		int right = n - 1;
		while (left<right) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			left++;
			right--;
		}
		return s;
	}
};