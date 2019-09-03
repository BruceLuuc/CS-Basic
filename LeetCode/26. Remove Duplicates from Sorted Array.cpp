#include"x.h"

//运行时间超时，提交失败
class Solution_0 {
public:
	int removeDuplicates(vector<int>& nums) {
		//记得边缘条件排除
		if (nums.empty())
			return 0;		
		for (auto i = nums.begin(); i !=prev(nums.end(),2); ++i){
			if (*i == *(i + 1))
				nums.erase(i);
		}
		return nums.size();
	}
};

//运行时间34ms
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

//运行时间30ms
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

//使用STL，时间复杂度O(n),空间复杂度O(1)
class Solution_4 {
public:
	int removeDuplicates(vector<int>& nums) {
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};


//unique的作用是“去掉”容器中相邻元素的重复元素（不一定要求数组有序），(注意是相邻)
//它会把重复的元素添加到容器末尾（所以数组大小并没有改变），而返回值是去重之后的尾地址
void delete_it(vector<int>&words)
{
	sort(words.begin(), words.end());
	vector<int>::iterator end_unique = unique(words.begin(), words.end());//把重复元素移到末尾
	words.erase(end_unique, words.end());// //删除（真正的删除）重复的元素
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