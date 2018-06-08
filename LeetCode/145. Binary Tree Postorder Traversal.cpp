#include"x.h"

//后序遍历
//递归
class Solution_145_1 {
public:
	vector<int>result;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root) {
			postorderTraversal(root->left);
			postorderTraversal(root->right);
			result.push_back(root->val);
		}
		return result;
	}
};

//栈
class Solution_145_2 {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<const TreeNode *> s;
		/* p正在访问的节点，q刚刚访问过的节点 */
		const TreeNode *p = root, *q = nullptr;

		do {
			while (p ) { /*往左下走 */
				s.push(p);
				p = p->left;
			}
			q= nullptr;
			while (!s.empty()) {
				p = s.top();
				s.pop();
				/* 右孩子不存在或已被访问，访问之 */
				if (p->right == q) {
					result.push_back(p->val);
					q = p; /* 保存刚访问过的节点 */
				}
				else {
					/* 当前节点不能访问，需第二次进栈 */
					s.push(p);
					/* 先处理右子树 */
					p = p->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};