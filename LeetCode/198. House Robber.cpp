#include"x.h"

//动态规划 超简单
class Solution_198_1 {
public:
	int rob(vector<int>&nums) {
		const int n = nums.size();
		if (n == 0)return 0;
		if (n == 1)return nums[0];
		if (n == 2)return max(nums[0], nums[1]);

		vector<int>f(n, 0);
		f[0] = nums[0];
		f[1] = max(nums[0],nums[1]);
		for (int i = 2; i != n; ++i) {
			f[i] = max(f[i-2]+nums[i],f[i-1]);
		}
		return f[n - 1];
	}
};

//优化空间，奇偶数跳着向前走
class Solution_198_2 {
public:
	int rob(vector<int>&nums) {
		int a = 0;
		int b = 0;
		for (int i = 0; i != nums.size(); ++i) {
			if (i % 2 == 0)
				a = max(a + nums[i], b);
			else
				b = max(a, b + nums[i]);
		}
		return max(a, b);
	}
};