#include"x.h"

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)return 0;
		//假设包含当前节点
		int res = findPath(root, sum);
		//不包含当前节点的值，转到左右自树中寻找
		res += pathSum(root->left, sum);
		res += pathSum(root->right, sum);

		return res;
	}
private:
	int findPath(TreeNode *node, int sum) {
		if (node == nullptr)return 0;
		int res = 0;
		if (node->val == sum)
			res += 1;
		//如果相加得到sum后  还要继续往下  因为有负数  加加减减之后可能重新得sum
		res += findPath(node->left, sum - node->val);
		res += findPath(node->right, sum - node->val);
		return res;
	}
};