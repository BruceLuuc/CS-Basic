#include"x.h"

//���ύ�Ĵ�
//�ж�nums.size()С����
//vectorȥ��erase
//map[gap]Ҫ����j
class Solution_3_1 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>result;
		if (nums.size() < 3) return result;
		unordered_map<int, int>_map;
		sort(nums.begin(), nums.end());

		for (int i=0;i!=nums.size();++i)
		{
			_map[nums[i]] = i;
		}

		for (int i = 0; i != nums.size()-1; ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i])
				continue;

			for (int j = i+1 ; j != nums.size()-1; ++j)
			{
				const int gap = 0 - nums[i] - nums[j];
				if (_map.find(gap) != _map.end()&&_map[gap]>j)//map[gap]Ҫ����j����>=
				{
						result.push_back({ nums[i], nums[j], gap});					
				}
			}
		}
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;

	}
};



//������Ȼ�����Ҽб�
class Solution_3_2 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3) return result;
		sort(nums.begin(), nums.end());
		const int target = 0;
		auto last = nums.end();

		/*
		''' X        Y       Z
		''' i        j       k
		'''last-3  last-2  last-1  last(β�������)
		*/

		for (auto i = nums.begin(); i < last - 2; ++i) 
		{	//����֮�󣬱����ų�������ȵ�������
			//������������ȣ�ֱ���ų�������target�ж�
			if (i > nums.begin() && *i == *(i - 1)) 
				continue;//����������һ��ѭ������һ�������������������������������ȣ���������
			auto k = last - 1;
			auto j = i + 1;
			while (j < k) 
			{
				if (*i + *j + *k < target) 
				{
					++j;
					while (*j == *(j - 1) && j < k) ++j;//��һ��ǰ��һ��֮�����ǰ��֮����ֵ���䣬*i + *j + *kֵҲ���䣬��Ҫ��һ����С��Χ��j����ǰ������++j
				}
				else if (*i + *j + *k > target) 
				{
					--k;
					while (*k == *(k + 1) && j < k) --k;
				}
				else 
				{
					result.push_back({ *i, *j, *k });
					++j;
					--k;
					while (*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
				}
			}
		}
		return result;
	}
};


int main_15()
{
	Solution_3_1 A;
	vector<int>a = { 1,2,-2,-1 ,5,1,1,-1,-2,3,-4};//{ 0,0,0 };
	auto result = A.threeSum(a);
	for (auto i : result)
	{
		print_vector(i);
	}
	

	system("pause");
	return 0;
}