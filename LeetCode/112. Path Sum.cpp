#include"x.h"
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//�սڵ�
		if (root == nullptr)return false;
		//�ݹ���ֹ����
		if (root->left == nullptr&&root->right==nullptr)
			return root->val == sum;
		return (hasPathSum(root->left, sum - root->val)) || (hasPathSum(root->right, sum - root->val));
	}
};