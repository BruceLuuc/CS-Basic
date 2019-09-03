#include"x.h"

class Solution_60_1 {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		for (int i = 0; i < n; ++i)
			s[i] += i + 1;
		for (int i = 0; i < k - 1; ++i)
			next_permutation(s.begin(), s.end());
		return s;
	}
};

//Î´µ÷ÊÔ³É¹¦
class Solution_60_2 {
public:
	string getPermutation(int n, int k) 
	{
		k--;
		int i, j;
		bool has[10] = { 0 };

		string result=(n,0);
		for (i = 0; i < n; ++i)
		{
			int tmp = k /fac(n - 1 - i);
			for (j = 0; j <= tmp; ++j)
				if (has[j]) tmp++;
			result[i] = tmp + 1;
			has[tmp] = 1;
			k %= fac(n - 1 - i);
		}
		return result;
	}



private:
	int fac(int n) 
	{
		int result = 1;
		for (int i = 1; i <= n; ++i)
			result *= i;
		return result;
	}

};
