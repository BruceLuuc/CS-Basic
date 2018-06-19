#include"x.h"

class Solution_70_1 {
public:
	int climbStairs(int n) {

		int result;

		int *arr = new int[n+1];
		memset(arr, 0, sizeof(arr));
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}

		result = arr[n];
		delete[] arr;
		return result;
	}
};

//����vector�����������
class Solution_70_1_ {
public:
	int climbStairs(int n) {
		vector<int>steps(n+1);
		steps[1] = 1;
		steps[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			steps[i] = steps[i - 1] + steps[i - 2];
		}
		return steps[n];
	}
};

//�Ż��ռ�
class Solution_70_2 {
public:
	int climbStairs(int n) {
		int prev = 0;
		int cur = 1;
		for (int i = 1; i <= n; ++i) {
			int tmp = cur;
			cur += prev;
			prev = tmp;
		}
		return cur;
	}
};


//�ݹ鷽�� ʱ�䳬ʱ 
class Solution_70_3 {
public:
	int climbStairs(int n) {
		return steps(n);
	}
private:
	int steps(int n)
	{
		if (n == 1){
			return 1;
		}
		else if (n == 2) {
			return 2;
		}
		else {
			return steps(n - 1) + steps(n - 2);
		}
	}
};

//�ݹ��Ż� ���仯���� �ύ�ɹ�beats96.86%
class Solution_70_4 {
public:
	int climbStairs(int n) {
		memo = vector<int>(n + 1, -1);
		return steps(n);
	}
private:
	vector<int>memo;
	int steps(int n)
	{
		if (n==0||n == 1) 
			return 1;
		if(memo[n]==-1)
			memo[n]= steps(n - 1) + steps(n - 2);
		return memo[n];
	}
};

//ֱ���׹�ʽ
//�ύ��beats�ʲ�2.21%���㲻��������
class Solution_70_5 {
public:
	int climbStairs(int n) {
		const double s = sqrt(5);
		//��׼�⺯��floor�����ز����ڸ�������������������ض�
		return floor((pow((1 + s) / 2, n + 1) + pow((1 - s) / 2, n + 1)) / s + 0.5);
	}
};