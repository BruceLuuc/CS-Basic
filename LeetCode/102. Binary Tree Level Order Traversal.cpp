#include"x.h"


//ßfšw
class Solution_102_1 {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traverse(root, 1, result);
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
		if (!root) return;
		if (level > result.size())
			result.push_back(vector<int>());
		result[level - 1].push_back(root->val);
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}
};

//µü´ú
class Solution_102_2 {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > result;
		queue<TreeNode*> current, next;
		if (root == nullptr) {
			return result;
		}
		else {
			current.push(root);
		}
		while (!current.empty()) {
			vector<int> level; // elments in one level
			while (!current.empty()) {
				TreeNode* node = current.front();
				current.pop();
				level.push_back(node->val);
				if (node->left != nullptr) next.push(node->left);
				if (node->right != nullptr) next.push(node->right);
			}
			result.push_back(level);
			swap(next, current);
		}
		return result;
	}
};