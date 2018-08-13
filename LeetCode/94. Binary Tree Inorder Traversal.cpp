#include"x.h"

//中序遍历
//递归
class Solution_94_1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>result;
		if (root!=nullptr) {
			inorderTraversal(root->left);
			result.push_back(root->val);
			inorderTraversal(root->right);
		}
		return result;
	}
};

//使用栈
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
				/*查找前驱 */
				TreeNode *node = cur->left;
				while (node->right  && node->right != cur)
					node = node->right;
				if (node->right == nullptr) { /* 还没线索化，则建立线索 */
					node->right = cur;
					/* prev = cur; 不能有这句，cur 还没有被访问 */
					cur = cur->left;
				}
				else { /* 已线索化，则删除线索 */
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