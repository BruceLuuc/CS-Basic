#include"x.h"

class Solution_16_1 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = INT_MAX;
		sort(nums.begin(), nums.end());
		for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
			auto b = next(a);
			auto c = prev(nums.end());
			while (b < c) 
			{
				const int sum = *a + *b + *c;
				const int tmp_gap = abs(sum - target);
				if (tmp_gap < min_gap) 
				{
					result = sum;
					min_gap = tmp_gap;//更新最小gap逼近target
				}
				//如果相加总和没有更加逼近target，即上一个判断条件不成立
				//，则不更新最小gap，开始左右夹逼
				if (sum < target) ++b;
				else --c;
			}
		}
		return result;
	}
};