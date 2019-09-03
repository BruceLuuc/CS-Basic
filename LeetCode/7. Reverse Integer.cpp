#include"x.h"

class Solution_7_1 {
public:
	int reverse(int x) {
		long long r = 0;
		long long t = x;

		t = t > 0 ? t : -t;
		for (; t; t /= 10)
			r = 10 * r + t % 10;

		bool negative = x < 0 ? true : false;
		if (r > INT_MAX || negative && r > INT_MAX)
			return 0;
		else
			return negative ? -r : r;
	}
};
