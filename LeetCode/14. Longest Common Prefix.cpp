#include"x.h"


//����
class Solution_14_1 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";

		for (int i = 0; i != strs[0].size(); ++i) {
			for (int j = 0; j != strs.size(); ++j) {
				//��j�еĵ�i��Ԫ�� �� ��0�еĵ�i��Ԫ�رȽ�
				if (strs[j][i] != strs[0][i])
					return strs[0].substr(0, i);//���ص�0�е�ǰi��Ԫ��
			}
		}

		return strs[0];
	}
};

//����
class Solution_14_2 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";
		int right = strs[0].size() - 1;
		for (int i = 1; i != strs.size(); ++i) {
			for (int j = 0; j <= right; ++j) {
				if (strs[i][j] != strs[0][j])
					right = j-1;//��һ�αȽ�ǰj-1��Ԫ�أ�����j-1
			}
		}
		return strs[0].substr(0, right+1);
	}
};