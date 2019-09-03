#include"x.h"

class Solution_33 {
public:
	int search(const vector<int>& nums, int target) {
		int first = 0, last = nums.size();
		while (first != last) {
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[first] <= nums[mid]) {
				if (nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else {
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};



class Solution_81 {
public:
	bool search(vector<int>& nums, int target) {
		int first =0,last=nums.size();
		while (first != last)
		{
			const int mid = first + (last - first) / 2;
			if (target == nums[mid])
				return true;
			
			if (nums[first] <= nums[mid])
			{
				//在第33题的基础上加入判断sums[first]~sums[mid]是否递增
				if (nums[first] < nums[mid])
				{
					if (nums[first] <= target && target <= nums[mid])
						last = mid;
					else
						first = mid + 1;
				}
				else
				{
					first++;
				}
			}
			else
			{
				if (nums[mid] <= target&&target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return false;


	}
};