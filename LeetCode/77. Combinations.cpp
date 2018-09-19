#include"x.h"

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution_77 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>result;
		vector<int>path;
		dfs(n, k, 1, 0, path, result);//从1开始1,2,3,4,...,n
		return result;
	}
private:
	static void dfs(int n, int k, int start, int cur, vector<int>&path, vector<vector<int>>&result) {
		if (cur == k) {
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; i++) {
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};