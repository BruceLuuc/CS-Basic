#include"x.h"


//二分法x^n=x^(n/2)*x^(n/2)*x^(n%2)
//分治法
class Solution_50_1 {
public:
	double myPow(double x, int n) {
		if (n < 0)return power(x, -n);
		else return power(x, n);
	}
private:
	double power(double x, int n) {
		if (n == 0)return 1;
		double v = power(x, n / 2);
		if (n % 2 == 0)return v * v;
		else return v * v*x;
	}
};