#include"x.h"


//纵向
class Solution_14_1 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";

		for (int i = 0; i != strs[0].size(); ++i) {
			for (int j = 0; j != strs.size(); ++j) {
				//第j行的第i个元素 和 第0行的第i个元素比较
				if (strs[j][i] != strs[0][i])
					return strs[0].substr(0, i);//返回第0行的前i个元素
			}
		}

		return strs[0];
	}
};

//横向
class Solution_14_2 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";
		int right = strs[0].size() - 1;
		for (int i = 1; i != strs.size(); ++i) {
			for (int j = 0; j <= right; ++j) {
				if (strs[i][j] != strs[0][j])
					right = j-1;//下一次比较前j-1个元素，包括j-1
			}
		}
		return strs[0].substr(0, right+1);
	}
};