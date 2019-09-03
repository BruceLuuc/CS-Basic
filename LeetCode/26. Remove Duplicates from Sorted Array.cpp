#include"x.h"

//����ʱ�䳬ʱ���ύʧ��
class Solution_0 {
public:
	int removeDuplicates(vector<int>& nums) {
		//�ǵñ�Ե�����ų�
		if (nums.empty())
			return 0;		
		for (auto i = nums.begin(); i !=prev(nums.end(),2); ++i){
			if (*i == *(i + 1))
				nums.erase(i);
		}
		return nums.size();
	}
};

//����ʱ��34ms
class Solution_2 {
public:
	int removeDuplicates(vector<int>& nums) {
		set<int>nums_1(nums.cbegin(), nums.cend());
		nums.clear();
		for (auto i = nums_1.begin(); i != nums_1.end(); ++i)
		{
			nums.push_back(*i);
		}
		return nums.size();
	}
};

//����ʱ��30ms
class Solution_3 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) 
			return 0;
		int index = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
		return index + 1;
	}
};

//ʹ��STL��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
class Solution_4 {
public:
	int removeDuplicates(vector<int>& nums) {
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};


//unique�������ǡ�ȥ��������������Ԫ�ص��ظ�Ԫ�أ���һ��Ҫ���������򣩣�(ע��������)
//������ظ���Ԫ����ӵ�����ĩβ�����������С��û�иı䣩��������ֵ��ȥ��֮���β��ַ
void delete_it(vector<int>&words)
{
	sort(words.begin(), words.end());
	vector<int>::iterator end_unique = unique(words.begin(), words.end());//���ظ�Ԫ���Ƶ�ĩβ
	words.erase(end_unique, words.end());// //ɾ����������ɾ�����ظ���Ԫ��
}
int main_26()
{
	vector<int>a = { 1,1,1,2,2,2,2,2,2,3,4,5,6,6,6,7,8,9,9,10,10 };
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		std::cout << *i;
		if (i != a.end() - 1)
		{
			std::cout << ",";
		}
	}
	std::cout << "\n";
	//unique(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (auto i = a.begin(); i!= a.end(); ++i)
	{
		std::cout << *i;
		if(i!=a.end()-1)
		{
			std::cout << ",";
		}		
	}
	std::cout << "\n";
	system("pause");
	return 0;
}