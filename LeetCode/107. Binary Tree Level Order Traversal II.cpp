#include"x.h"

//���������
//����102��ֱ��Ĭд
class Solution_107_1 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int> >result;
		if (!root)return result;
		queue<TreeNode*>current, next;
		current.push(root);

		while (!current.empty()) {
			vector<int>level;
			while (!current.empty()) {
				TreeNode*p = current.front();
				level.push_back(p->val);
				current.pop();
				if (p->left)next.push(p->left);
				if (p->right)next.push(p->right);
			}
			result.push_back(level);
			swap(current, next);
		}
		reverse(result.begin(), result.end());//��102��Ļ����ϼ���һ��
		return result;
	}
};

class Solution_107_2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int> >result;
		traverse(root, 1, result);
		reverse(result.begin(), result.end());//��102��Ļ����ϼ���һ��
		return result;
	}
	void traverse(TreeNode*root, size_t level, vector<vector<int> >&result) {
		if (!root)return;
		if (level>result.size())
			result.push_back(vector<int>());
		result[level - 1].push_back(root->val);
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}
};