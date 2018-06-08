#include"x.h"

class Solution_7_1 {
public:
	int reverse(int x) {
		long long r = 0;
		long long t = x;

		t = t > 0 ? t : -t;
		for (; t; t /= 10)
			r = 10 * r + t % 10;

		bool sign = x > 0 ? false : true;
		if (r > INT_MAX || (sign && r > INT_MAX)) {
			return 0;
		}
		else {
			if (sign) {
				return -r;
			}
			else {
				return r;
			}
		}
	}
};


int main_7()
{
	int a = -1234560;
	int c = a & 1;
	int d = 10 & 1;
	int e = 9 & 1;

	Solution_7_1 b;
	std::cout << b.reverse(a) << std::endl;
	std::cout << c << "," << d << "," << e << "\n";
	system("pause");
	return 0;
}