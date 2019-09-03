#include"x.h"


class Solution {
public:
	int romanToInt(string s) {

		map<char, int>m = {
		{'I',1},
		{'V',5 },
		{'X',10 },
		{'L',50 },
		{'C',100 },
		{'D',500 },
		{'M',1000 }
		};
		int res=0;
		for (int i = 0; i < s.size(); ++i)
		{
			int val = m[s[i]];
			if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
				res += val;
			else res -= val;

		}
		return res;
	}
};

int main13_()
{
	Solution a;
	cout << "III:3---> "<<a.romanToInt("III") << endl;
	cout << "IV:4---> " << a.romanToInt("IV") << endl;
	cout << "VI:6---> " << a.romanToInt("VI") << endl;
	cout << "IX:9---> " << a.romanToInt("IX") << endl;
	cout << "LVIII:58---> " << a.romanToInt("LVIII") << endl;
	cout << "MCMXCIV:1994---> " << a.romanToInt("MCMXCIV") << endl;

	system("pause");
	return 0;
}