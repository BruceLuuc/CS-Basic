#include"x.h"
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//空节点
		if (root == nullptr)return false;
		//递归终止条件
		if (root->left == nullptr&&root->right==nullptr)
			return root->val == sum;
		return (hasPathSum(root->left, sum - root->val)) || (hasPathSum(root->right, sum - root->val));
	}
};