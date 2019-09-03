#include"x.h"

/*
Given a collection of distinct integers, return all possible permutations.
全排列问题
Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
//31. Next Permutation
class Solution_next {
public:
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
};
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
class Solution_46_1 {
public:
	vector<vector<int>>permute(vector<int>&num) {
		sort(num.begin(), num.end());
		vector<vector<int>>result;
		vector<int>path;
		dfs(num, path, result);
		return result;
	}
private:
	void dfs(const vector<int>&num, vector<int>&path, vector<vector<int>>&result) {
		if (path.size() == num.size()) {
			result.push_back(path);
			return;
		}
		for (auto i : num) {
			auto pos = find(path.begin(), path.end(), i);
			if (pos == path.end()) {
				path.push_back(i);
				dfs(num, path, result);
				path.pop_back();
			}
		}
	}
};
class Solution_46_2 {
public:
	vector<vector<int>>permute(vector<int>&num) {
		vector<vector<int>>result;
		dfs(num, 0, result);
		return result;
	}
private:
	void dfs(vector<int>&num, int index, vector<vector<int>>&result) {
		if (index == num.size() ){
			result.push_back(num);
			return;
		}
		for (int i = index; i < num.size(); ++i) {
			swap(num[index], num[i]);
			dfs(num, index + 1, result);
			swap(num[index], num[i]);
		}
	}
};
/*
当n=1时，数组中只有一个数a1，其全排列只有一种，即为a1

当n=2时，全排列:a1a2和a2a1，在a1的前后两个位置分别加入了a2

当n=3时，数组中有a1a2a3，那么根据上面的结论，在a1a2和a2a1的基础上在不同的位置上加入a3得到:

_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3

_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
*/
class Solution_3 {
public:
	vector<vector<int> > permute(vector<int> &num) {
		if (num.empty()) return vector<vector<int> >(1, vector<int>());
		vector<vector<int> > res;
		int first = num[0];
		num.erase(num.begin());
		vector<vector<int> > words = permute(num);
		for (auto &a : words)
			for (int i = 0; i <= a.size(); ++i) {
				a.insert(a.begin() + i, first);
				res.push_back(a);
				a.erase(a.begin() + i);
			}
		return res;
	}
};


//全部组合数 77. Combinations
class Solution_77 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>result;
		vector<int>path;
		dfs(n, k, 1, 0, path, result);//从1开始1,2,3,4,...,n
		return result;
	}
private:
	static void dfs(int n, int k, int start, int cur, vector<int>&path, vector<vector<int>>&result) {
		if (cur == k) {
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; i++) {
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};