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

/*
全排列LeetCode#46
*/

void nextPermutation(vector<int>& nums) {
	int n = nums.size(), i = n - 2, j = n - 1;
	while (i >= 0 && nums[i] >= nums[i + 1])
		--i;
	if (i >= 0) {
		while (nums[j] <= nums[i])
			--j;
		swap(nums[i], nums[j]);
	}
	reverse(nums.begin() + i + 1, nums.end());
}
class Solution_next_permutation {
public:
	void nextPermutation(vector<int> &nums) {
		next_permutation(nums.begin(), nums.end());
	}
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last) {
		// Get a reversed range to simplify reversed traversal.
		const auto rfirst = reverse_iterator<BidiIt>(last);//改变迭代器方向
		const auto rlast = reverse_iterator<BidiIt>(first);
		// Begin from the second last element to the first element.
		auto pivot = next(rfirst);
		// Find `pivot`, which is the first element that is no less than its
		// successor. `Prev` is used since `pivort` is a `reversed_iterator`.
		while (pivot != rlast && *pivot >= *prev(pivot))
			++pivot;
		// No such elemenet found, current sequence is already the largest
		// permutation, then rearrange to the first permutation and return false.
		if (pivot == rlast) {
			reverse(rfirst, rlast);
			return false;
		}
		// Scan from right to left, find the first element that is greater than `pivot`.
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rfirst, pivot);
		return true;
	}
};
class Solution_46 {
public:
	vector<vector<int>> permuteUnique(vector<int>& num) {
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		do {
			result.push_back(num);
		} while (next_permutation(num.begin(), num.end()));
		return result;
	}
};




//# LCS #最长公共子序列(Longest-Common-Subsequence)
//动态规划问题
int LCS_length(const string& x, const string& y) {
	const int m = x.size();
	const int n = y.size();
	if (m == 0 || n == 0)return 0;
	vector<vector<int>>f(m + 1, vector<int>(n + 1, 0));
	for(int i=1;i<=m;i++)
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i][j - 1], f[i - 1][j]);
		}
	return f[m][n];
}