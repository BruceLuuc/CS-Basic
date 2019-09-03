#include"x.h"

class Solution_55 {
public:
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		int reach = 0;
		for (int i = 0; i <= reach&&reach < n-1; i++)
			reach = max(reach, i + nums[i]);
		return reach >= n-1;
	}
};

class Solution_55_2 {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return true;
		const int n = nums.size();
		int left_most = n - 1;
		for (int i = n - 2; i >= 0; i--)
			if (i + nums[i] >= left_most)
				left_most = i;
		return left_most == 0;
	}
};