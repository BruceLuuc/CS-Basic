#include"x.h"

//��һ��
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

//�Ż�֮��
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

//���Ҽб�
class Solution_9_3 {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int d = 1; // divisor
		//������������������121��d=100;6666,d=1000
		while (x / d >= 10) d *= 10;

		while (x > 0) {
			int q = x / d; // quotient��
			int r = x % 10; // remainder����
			if (q != r) return false;
			x = x % d / 10;//ȥ�����Ϊ�����λ
			d /= 100;
		}
		return true;
	}
};
