#include"x.h"

class Solution_31_1 {
public:
	void nextPermutation(vector<int>& nums) {
		int index = nums.size() - 1;
		while (nums[index] <= nums[index - 1]) {
			--index;
		}
		if (index == 0) {
			sort(nums.begin(), nums.end());
			return;
		}

		int min_max = INT_MAX, min_max_Index = INT_MAX;
		for (int i = nums.size() - 1; i >= index - 1; --i) {
			if (nums[i] > nums[index - 1]) {
				if (nums[i] < min_max) {
					min_max = nums[i];
					min_max_Index = i;
				}
			}
		}

		swap(nums[index - 1], nums[min_max_Index]);

		sort(nums.begin() + index, nums.end());
	}
};

/*

class Solution_31_2 {
public:
	void nextPermutation(vector<int> &nums) {
		_next_permutation(nums.begin(), nums.end());
	}
	template<typename BidiIt>
	bool _next_permutation(BidiIt first, BidiIt last) {
		// Get a reversed range to simplify reversed traversal.
		const auto rfirst = reverse_iterator<BidiIt>(last);
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
		// Scan from right to left, find the first element that is greater than
		// `pivot`.
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rfirst, pivot);
		return true;
	}
};
*/