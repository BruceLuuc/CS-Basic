#include"x.h"

//左右夹逼法，同16题
class Solution_18_1 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		vector<vector<int>>result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());

		for (auto a = nums.begin(); a < prev(nums.end(), 3); ++a)
		{
			for (auto b = next(a); b < prev(nums.end(), 2); ++b)
			{
				auto c = next(b);
				auto d = prev(nums.end(), 1);
				while (c < d)
				{
					int sum = *a + *b + *c + *d;
					if (sum > target)--d;
					else if (sum < target)++c;
					else
					{
						result.push_back({ *a,*b,*c,*d });
						++c;
						--d;
					}
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};

class Solution_18_2 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());

		unordered_map<int, vector<pair<int, int>>>cache;//键值不重复，对应多个pair
		//先缓存两个数的和
		for (size_t a = 0; a < nums.size(); ++a)
		{
			for (size_t b = a + 1; b < nums.size(); ++b)
			{
				//nums[a] + nums[b]是下标 键值，用两个数的和作为键值，便于后面查找
				cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
			}
		}


		for (int c = 0; c < nums.size(); ++c)
		{
			for (size_t d = c + 1; d < nums.size(); ++d)
			{
				const int key = target - nums[c] - nums[d];//动态计算c,d,在cache里面查找
				if (cache.find(key) == cache.end()) continue;
				//创建一个引用，便于代码阅读
				//vec是查找到的pair，(可能查找到多对pair,一个键值对应多个内容的情况)
				//pair中第一个数存nums的下标a，，若要得到数nums[vec[k].first]
				const auto&vec = cache[key];

				for (size_t k = 0; k < vec.size(); ++k)
				{
					if (c <= vec[k].second)
						continue;//保证a,b,c,d下标从小到大排列，且不重复
					result.push_back({ 
						nums[vec[k].first],
						nums[vec[k].second], 
						nums[c], 
						nums[d] 
						});
				}

			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;

	}
};

class Solution_18_3 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());

		//先存入两个数的和，然后在里面配对
		unordered_multimap<int, pair<int, int>> cache;//键值会重复，把所有两两相加的情况存入进去
		for (int i = 0; i < nums.size()-1; ++i)
			for (int j = i + 1; j < nums.size(); ++j)
				cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));

		//配对
		for (auto i = cache.begin(); i != cache.end(); ++i) 
		{
			int x = target - i->first;
			auto range = cache.equal_range(x);//找到同一键值对应的所有情况，开始遍历
			for (auto j = range.first; j != range.second; ++j) 
			{
				auto a = i->second.first;
				auto b = i->second.second;
				auto c = j->second.first;
				auto d = j->second.second;

				//保证元素不重复，下标不重复
				if (a != c && a != d && b != c && b != d) 
				{
					vector<int>vec = { nums[a],nums[b],nums[c],nums[d] };
					sort(vec.begin(), vec.end());
					result.push_back(vec);
				}
			}
		}


		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};


//对方法一的优化，时间复杂度O(n^3logn),空间复杂度O(1)，提交超时
//表面上优化了，实际上更慢了！
//晦涩难懂！不看也罢！
class Solution_18_4 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());


		auto last = nums.end();
		for (auto a = nums.begin(); a < prev(last, 3);a = upper_bound(a, prev(last, 3), *a)) 
		{
			for (auto b = next(a); b < prev(last, 2);
				b = upper_bound(b, prev(last, 2), *b)) {
				auto c = next(b);
				auto d = prev(last);
				while (c < d) {
					if (*a + *b + *c + *d < target) {
						c = upper_bound(c, d, *c);
					}
					else if (*a + *b + *c + *d > target) {
						d = prev(lower_bound(c, d, *d));
					}
					else {
						result.push_back({ *a, *b, *c, *d });
						c = upper_bound(c, d, *c);
						d = prev(lower_bound(c, d, *d));
					}
				}
			}
		}
		return result;

	}
};