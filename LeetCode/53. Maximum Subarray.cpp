#include"x.h"

//215ms Bad
class Solution_53_1 {
public:
	int maxSubArray(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0)return 0;
		int result=nums[0];
		int tmp;

		for (int i = 0; i != n; ++i) {
			tmp = 0;
			for (int j = i; j != n; ++j) {
				tmp += nums[j];
				if (tmp > result) {
					 result=tmp;
				}
			}
		}
		return result;
	}
};