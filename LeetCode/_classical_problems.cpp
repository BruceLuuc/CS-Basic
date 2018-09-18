#include"x.h"

//LeetCode#53 最大子序列和  子序列：连续的子串
/*
*  当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？它只有两种选择：加入之前的SubArray、另起一个SubArray。
*  如果之前SubArray的总体和大于0的话，我们认为其对后续结果是有贡献的。这种情况下我们选择加入之前的SubArray。
*  如果之前SubArray的总体和为0或者小于0的话，我们认为其对后续结果是没有贡献，甚至是有害的，这种情况下选择以这个数字开始，另起一个SubArray
*
*/
int maxSum(const vector<int>&nums) {
	int result = INT_MIN;
	int tmpSum = 0;
	for (auto i : nums) {
		tmpSum += i;
		result = max(result, tmpSum);
		if (tmpSum < 0)
			tmpSum = 0;//截断 另起一个子串
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