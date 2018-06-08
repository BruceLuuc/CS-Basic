#include"x.h"

//�������
//�ݹ�
class Solution_94_1 {
public:
	vector<int>result;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root) {
			inorderTraversal(root->left);
			result.push_back(root->val);
			inorderTraversal(root->right);
		}
		return result;
	}
};

//ʹ��ջ
class Solution_94_2 {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		const TreeNode *p = root;

		while (!s.empty() || p ) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top();
				s.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}
};


//Mrris
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		TreeNode *cur = root, *prev = nullptr;
		while (cur) {
			if (cur->left == nullptr) {
				result.push_back(cur->val);
				prev = cur;
				cur = cur->right;
			}
			else {
				/*����ǰ�� */
				TreeNode *node = cur->left;
				while (node->right  && node->right != cur)
					node = node->right;
				if (node->right == nullptr) { /* ��û���������������� */
					node->right = cur;
					/* prev = cur; ��������䣬cur ��û�б����� */
					cur = cur->left;
				}
				else { /* ������������ɾ������ */
					result.push_back(cur->val);
					node->right = nullptr;
					prev = cur;
					cur = cur->right;
				}
			}
		}
		return result;
	}
};