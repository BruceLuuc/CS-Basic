#include"x.h"


//前序遍历
//使用递归  题目不推荐
class Solution_144_1 {
public:
	vector<int>result;
	vector<int> preorderTraversal(TreeNode* root) {
		if (root) {
			result.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return result;
	}
};

//栈
class Solution_144_2 {
public:
	vector<int>preorderTraversal(TreeNode* root) {
		vector<int>result;
		stack<TreeNode*>s;
		if (root) s.push(root);

		while (!s.empty()) {
			TreeNode*p = s.top();
			result.push_back(p->val);
			s.pop();
			if (p->right)s.push(p->right);
			if (p->left)s.push(p->left);
		}
		return result;
	}
};

//Morris先序遍历 看懂
class Solution_144_3 {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		TreeNode *cur = root, *prev = nullptr;

		while (cur) {
			if (cur->left == nullptr) {
				result.push_back(cur->val);
				prev = cur; /* cur刚刚被访问过 */
				cur = cur->right;
			}
			else {
				/* 查找前驱 */
				TreeNode *node = cur->left;
				while (node->right != nullptr && node->right != cur)
					node = node->right;
				if (node->right == nullptr) { /*还没线索化，则建立线索*/
					result.push_back(cur->val); /*仅这一行的位置与中序不同*/
					node->right = cur;
					prev = cur; /* cur刚刚被访问过 */
					cur = cur->left;
				}
				else { /* 已线索化，则删除线索 */
					node->right = nullptr;
					/* prev = cur; 不能有这句，cur 已经被访问 */
					cur = cur->right;
				}
			}
		}
		return result;
	}
};