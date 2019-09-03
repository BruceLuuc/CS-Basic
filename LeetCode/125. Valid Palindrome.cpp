#include"x.h"

//错误 Runtime Error
//修复之后 beats 4.98% ...
class Solution_125_1 {
public:
	bool isPalindrome(string s) {
		if (s.empty())return true;
		vector<char>vec;
		for (auto i:s) {
			if (isalnum(i)) {
				vec.push_back(tolower(i));
			}				
		}
		//第一遍忘记了加空判断，边界条件要时刻记得检查！！
		if (vec.empty()) return true;
		for (int i = 0; i != vec.size()/2+1; ++i) {
			if (vec[i] != vec[vec.size() - i - 1])
				return false;
		}
		return true;

	}
};

//利用STL转换成小写，然后左右夹逼 比对字符
class Solution_125_2 {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left < right) {
			if (!::isalnum(*left)) ++left;
			else if (!::isalnum(*right)) --right;
			else if (*left != *right) return false;
			else { left++, right--; }
		}
		return true;
	}
};