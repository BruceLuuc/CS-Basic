#include"x.h"

class Solution_136_1 {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			result ^= nums[i];
		}
		return result;
	}
};

//用标准库简写上述函数
class Solution_136_2 {
public:
	int singleNumber(vector<int>& nums) {
		return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	}
};

//用map做，适用于137_Single_Number II
class Solution_136_3{
public:
	int singleNumber(vector<int> &nums){
		unordered_map<int, int> cnts;    // {number, count}  
		for (auto x : nums){
			if (cnts.find(x) != cnts.end())
				cnts[x]++;
			else
				cnts.insert({ x, 1 });
		}

		for (auto x : cnts)
		{
			if (x.second != 2)
				return x.first;
		}
		return 0;
	}
};

class Solution_136_4 {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size(); i += 2)
			if (nums[i] != nums[i + 1])
				return nums[i];
		return 0;
	}
};