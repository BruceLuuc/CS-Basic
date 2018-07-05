#include"x.h"

class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> _map;
		vector<int>result;
		for (auto i = 0; i != nums.size(); ++i)
		{
			_map[nums[i]] = i;
		}
		for (auto i = 0; i != nums.size(); ++i)
		{
			const int gap = target - nums[i];
			if (_map.find(gap)!= _map.end() && _map[gap] > i)
			{
				result.push_back(i);
				result.push_back(_map[gap]);
            }
		}
		return result;
    }
};