#include"x.h"

//LeetCode#53 最大子序列和  子序列：连续的子串
int maxSum(const vector<int>&nums) {
	int result = INT_MIN;
	int tmpSum = 0;
	for (auto i : nums) {
		tmpSum += i;
		result = max(result, tmpSum);
		if (tmpSum < 0)
			tmpSum = 0;
	}
	return result;
}
int maxSubArray(const vector<int>& nums) {
	int result = INT_MIN;
	int tmpSum = 0;
	for (auto i : nums) {
		tmpSum = max(tmpSum + i, i);
		result = max(result, tmpSum);
	}
	return result;
}