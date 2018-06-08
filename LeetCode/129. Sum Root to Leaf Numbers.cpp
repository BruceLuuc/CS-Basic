#include"x.h"

class Solution_129_1 {
public:
	int sumNumbers(TreeNode* root) {
		return dfs(root, 0);
	}
private:
	int dfs(TreeNode *root, int sum) {
		if (!root) return 0;
		if (!root->left && !root->right)
			return sum * 10 + root->val;
		return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
	}
};