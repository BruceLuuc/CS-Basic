#include"x.h"

//���� Runtime Error
//�޸�֮�� beats 4.98% ...
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
		//��һ�������˼ӿ��жϣ��߽�����Ҫʱ�̼ǵü�飡��
		if (vec.empty()) return true;
		for (int i = 0; i != vec.size()/2+1; ++i) {
			if (vec[i] != vec[vec.size() - i - 1])
				return false;
		}
		return true;

	}
};

//����STLת����Сд��Ȼ�����Ҽб� �ȶ��ַ�
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