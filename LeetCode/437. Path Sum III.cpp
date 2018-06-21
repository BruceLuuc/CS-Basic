#include"x.h"

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)return 0;
		//���������ǰ�ڵ�
		int res = findPath(root, sum);
		//��������ǰ�ڵ��ֵ��ת������������Ѱ��
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
		//�����ӵõ�sum��  ��Ҫ��������  ��Ϊ�и���  �ӼӼ���֮��������µ�sum
		res += findPath(node->left, sum - node->val);
		res += findPath(node->right, sum - node->val);
		return res;
	}
};