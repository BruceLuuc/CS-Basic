#include"x.h"

//�ݹ� ʱ�䳬ʱ �ύʧ��
class Solution_343_1 {
private:
	int max3(int a, int b, int c) {
		return max(a, max(b, c));
	}

	int breakInteger(int n) {
		if (n == 1)return 1;
		int res = -1;

		for (int i = 1; i!= n; ++i)
			//���ٷָ���������� ��Ҫ����i*(n-i)��n-i���ָ�
			res=max3(res,i*(n-i),i*breakInteger(n - i));
		return res;
	}

public:
	int integerBreak(int n) {
		return breakInteger(n);
	}
};


//�Ż��ݹ� ���仯����  beats100%
class Solution_343_2 {
private:
	vector<int>memo;
	int max3(int a, int b, int c) {
		return max(a, max(b, c));
	}

	int breakInteger(int n) {
		if (n == 1)return 1;
		if (memo[n] != -1)return memo[n];

		int res = -1;

		for (int i = 1; i != n; ++i)
			res = max3(res, i*(n - i), i*breakInteger(n - i));
		memo[n] = res;
		return res;
	}
public:
	int integerBreak(int n) {
		assert(n >= 2);
		memo = vector<int>(n + 1, -1);
		return breakInteger(n);
	}
};


//��̬�滮 beats100%
class Solution_343_3 {
private:
	int max3(int a, int b, int c) {
		return max(a, max(b, c));
	}

public:
	int integerBreak(int n) {
		assert(n >= 2);
		vector<int>memo(n + 1, -1);
		memo[1] = 1;
		memo[2] = 1;

		int res = -1;
		for (int i = 3; i <= n; ++i) {
			//for(int j = 1; j!= i; ++j)�Ż� ����һ�뼴��
			for (int j = 1; j != i/2+1; ++j) {
				res = max3(res, j*(i - j), j*memo[i - j]);				
			}
			memo[i] = res;
		}				
		return memo[n];
	}
};