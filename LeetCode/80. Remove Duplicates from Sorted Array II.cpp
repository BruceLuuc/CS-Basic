#include"x.h"

class Solution_1 {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size()<=2)
			return nums.size();

		int index = 2;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		}
		return index;

	}
};

class Solution_2 {
public:
	int removeDuplicates(vector<int>& nums) {
		const int n = nums.size();
		int index = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
				continue;
			nums[index++] = nums[i];
		}
		return index;
	}
};