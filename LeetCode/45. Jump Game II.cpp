#include"x.h"

class Solution_45_1 {
public:
	int jump(vector<int>&nums) {
		const int n = nums.size();
		if (n == 1)return 0;
		int step = 0;
		int left = 0;
		int right = 0;
		while (left <= right) {
			++step;
			const int old_right = right;
			for (int i = left; i <= old_right; ++i) {
				if (i + nums[i] >= n - 1)return step;
				if (i + nums[i] > right)right = i + nums[i];
			}
			left = old_right + 1;
		}
		return 0;
	}
};

class Solution_55_2 {
public:
	int jump(vector<int>& nums) {
		const int n = nums.size();
		if (n == 1)return 0;
		int step = 0;
		int left = 0;
		int right = 0;

		for (int i = 0; i != n; ++i) {
			if (i>right) {
				right = left;
				++step;
			}
			left = max(left, i + nums[i]);
		}
		return step;
	}
};
