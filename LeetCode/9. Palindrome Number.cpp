#include"x.h"

//第一遍
class Solution_9_1 {
public:
	bool isPalindrome(int x) {
		if (x < 0)return false;
		int re = 0,t=x;
		while (t) {
			re = re * 10 + t % 10;
			t /= 10;
		}

		if (re == x)return true;
		else return false;
	}
};

//优化之后
class Solution_9_2 {
public:
	bool isPalindrome(int x)
	{
		long tmp = abs(x);
		long reverse = 0;

		while (tmp)
		{
			reverse = reverse * 10 + (tmp % 10);
			tmp /= 10;
		}
		return reverse == x;
	}
};

//左右夹逼
class Solution_9_3 {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int d = 1; // divisor
		//获得最高数量级，比如121，d=100;6666,d=1000
		while (x / d >= 10) d *= 10;

		while (x > 0) {
			int q = x / d; // quotient商
			int r = x % 10; // remainder余数
			if (q != r) return false;
			x = x % d / 10;//去掉最高为和最低位
			d /= 100;
		}
		return true;
	}
};
