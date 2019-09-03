#include"x.h"

//暴力遍历
class Solution_35_1 {
public:
	int searchInsert(vector<int>& nums, int target) {	
		if (target>nums[nums.size() - 1])return nums.size();
		if (target<nums[0])return 0;

		int result = 0;

		for (int i = 0; i != nums.size(); ++i) 
			if (!(nums[i]<target)){
				result = i;
				break;
			}
		return result;
	}
};

//重新实现lower_bound  O(logN)
class Solution_35_2 {
public:
	int searchInsert(vector<int>&nums, int target) {
		return distance(nums.begin(), _lower_bound(nums.begin(), nums.end(), target));
	}
private:
	template<typename ForwardIterator,typename T>
	ForwardIterator _lower_bound(ForwardIterator first, ForwardIterator last, T val) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (val > *mid)first = ++mid;
			else last = mid;
		}
		return first;
	}
};