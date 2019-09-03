#include"x.h"

//���ҼбƷ���ͬ16��
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

		unordered_map<int, vector<pair<int, int>>>cache;//��ֵ���ظ�����Ӧ���pair
		//�Ȼ����������ĺ�
		for (size_t a = 0; a < nums.size(); ++a)
		{
			for (size_t b = a + 1; b < nums.size(); ++b)
			{
				//nums[a] + nums[b]���±� ��ֵ�����������ĺ���Ϊ��ֵ�����ں������
				cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
			}
		}


		for (int c = 0; c < nums.size(); ++c)
		{
			for (size_t d = c + 1; d < nums.size(); ++d)
			{
				const int key = target - nums[c] - nums[d];//��̬����c,d,��cache�������
				if (cache.find(key) == cache.end()) continue;
				//����һ�����ã����ڴ����Ķ�
				//vec�ǲ��ҵ���pair��(���ܲ��ҵ����pair,һ����ֵ��Ӧ������ݵ����)
				//pair�е�һ������nums���±�a������Ҫ�õ���nums[vec[k].first]
				const auto&vec = cache[key];

				for (size_t k = 0; k < vec.size(); ++k)
				{
					if (c <= vec[k].second)
						continue;//��֤a,b,c,d�±��С�������У��Ҳ��ظ�
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

		//�ȴ����������ĺͣ�Ȼ�����������
		unordered_multimap<int, pair<int, int>> cache;//��ֵ���ظ���������������ӵ���������ȥ
		for (int i = 0; i < nums.size()-1; ++i)
			for (int j = i + 1; j < nums.size(); ++j)
				cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));

		//���
		for (auto i = cache.begin(); i != cache.end(); ++i) 
		{
			int x = target - i->first;
			auto range = cache.equal_range(x);//�ҵ�ͬһ��ֵ��Ӧ�������������ʼ����
			for (auto j = range.first; j != range.second; ++j) 
			{
				auto a = i->second.first;
				auto b = i->second.second;
				auto c = j->second.first;
				auto d = j->second.second;

				//��֤Ԫ�ز��ظ����±겻�ظ�
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


//�Է���һ���Ż���ʱ�临�Ӷ�O(n^3logn),�ռ临�Ӷ�O(1)���ύ��ʱ
//�������Ż��ˣ�ʵ���ϸ����ˣ�
//��ɬ�Ѷ�������Ҳ�գ�
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