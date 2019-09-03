#include"x.h"

class Solution_113 {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>>result;
		vector<int>cur;
		pathSum(root, sum, cur, result);
		return result;
	}
	void pathSum(TreeNode* root, int sum, vector<int>&cur, vector<vector<int>>&result) {
		if (root == nullptr)return;
		cur.push_back(root->val);
		if (root->left == nullptr&&root->right == nullptr&&sum == root->val)
			result.push_back(cur);
		pathSum(root->left, sum - root->val, cur, result);
		pathSum(root->right, sum - root->val, cur, result);
		cur.pop_back();
	}
};