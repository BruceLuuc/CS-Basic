#include"x.h"

//µÝ¹é ²»¶®
class Solution_1 {
private:
	vector <vector<int>>memo;

	bool tryPartition(const vector<int>&nums, int index, int sum) {
		if (sum == 0)return true;
		if (sum < 0 || index < 0)return false;

		if (memo[index][sum] != -1)
			return memo[index][sum] == 1;

		memo[index][sum]=(tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index]))?1:0;
		return memo[index][sum] == 1;

	}
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums)
			sum += i;		
		if (sum % 2 != 0)return false;

		memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
		return tryPartition(nums, nums.size()-1, sum / 2);
	}
};


//µü´ú ²»¶®
class Solution_2 {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum % 2 != 0)return false;

		int n = nums.size();
		int C = sum / 2;
		vector<bool>memo(C+1,false);

		for (int i = 0; i <= C; ++i) {
			memo[i] = (nums[0] == i);
		}

		for (int i = 1; i < n; ++i) {
			for (int j = C; j >= nums[i]; --j) {
				memo[j] = memo[j] || memo[j - nums[i]];
			}
		}
		return memo[C];

	}
};