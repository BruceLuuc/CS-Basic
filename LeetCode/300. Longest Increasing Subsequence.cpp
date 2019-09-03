#include"x.h"


//错误算法
class Solution_1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0)return 0;
		int result = 0;

		for (int i = 0; i!= n; ++i) {
			vector<int>tmp;
			tmp.push_back(nums[i]);
			for (int j = i + 1; j != n; ++j) {
				if (nums[j] > tmp.back()) {
					tmp.push_back(nums[j]);
				}
			}
			result = max(result, tmp.size());
		}
		return result;
	}
};


//最长上升子序列 O(n^2)
class Solution_2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0)return 0;
		int result = 0;
  
		vector<int>memo(n, 1);
		for (int i = 1; i != n; ++i) 
			for (int j = 0; j != i; ++j) 
				if (nums[j] < nums[i])
					memo[i] = max(memo[i], memo[j] + 1);
		sort(memo.begin(), memo.end());
		return memo.back();
	}
};


//拓展 求出具体解
class Solution_test {
private:
	vector<int>res;
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0)return 0;
		int result = 0;

		map<int, int>map_;
		map_[1] = 0;
		vector<int>memo(n, 1);
		for (int i = 1; i != n; ++i) {
			for (int j = 0; j != i; ++j) {
				if (nums[j] < nums[i]) {
					memo[i] = max(memo[i], memo[j] + 1);
				}
			}
			map_[memo[i]] = i;
		}
		sort(memo.begin(), memo.end());

		for (int i = memo.back(); i >= 1; --i) {
			res.push_back(nums[map_[i]]);
		}
		reverse(res.begin(), res.end());

		for (auto i : res) {
			cout << i << "  ";
		}
		cout << endl;

		return memo.back();
	}
};


int main_300() {
	Solution_test A;
	vector<int>a = { 10,9,2,5,3,7,101,18 };
	vector<int>b = {10,9,2,2,5,98,3,3,4,4};
	vector<int>c = { 10,9,2,5,3,3,3,3,4,4,4,87,87,5,5,6 };

	cout << A.lengthOfLIS(c)<<endl;

	system("pause");
	return 0;
}