#include"x.h"

class Solution_560 {
public:
	int subarraySum(vector<int>&nums, int k) {
		const int n = nums.size();
		int sum = 0;
		int res = 0;
		unordered_map<int, int>map;
		map[0] = 1;
		for (int i = 0; i != n; ++i) {
			sum += nums[i];
			res += map[sum - k];
			map[sum] += 1;
		}
		return res;
	}
};