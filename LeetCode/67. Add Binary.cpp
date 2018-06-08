#include"x.h"

class Solution_67_1 {
public:
	string addBinary(string a, string b) {
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		//注意字符和整型的转换，加减'0'即可
		for (int i = 0; i != n; ++i)
		{
			const int ai = i < a.size() ? a[i]-'0':0;
			const int bi = i < b.size() ? b[i]-'0':0;
			const int val = (ai + bi + carry) % 2;
			carry= (ai + bi + carry)/2;

			result.insert(result.begin(), val+'0');
		}
		if(carry==1)
			result.insert(result.begin(), '1');
		return result;
	}
};