#include"x.h"

class Solution_8_1 {
public:
	int myAtoi(string str) {
		int num = 0;
		int sign = 1;
		const int n = str.length();
		int i = 0;

		while (str[i]==' ') i++;

		if (str[i] == '+')
			i++;
		else if (str[i] == '-')	{				
			sign = -1; 			
			i++;
		}
		

		for (; i!= n; ++i) {
			if (str[i]<'0' || str[i]>'9')
				break;
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
				return sign == -1 ? INT_MIN : INT_MAX;
			num = num * 10 + str[i] - '0';
		}

		return num * sign;

	}
};

int main_8()
{

	string a= "+-2";
	Solution_8_1 A;
	cout << A.myAtoi(a)<<endl;
	system("pause");
	return 0;
}