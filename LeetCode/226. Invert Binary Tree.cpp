#include"x.h"

class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (root == nullptr)return nullptr;
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
		return root;
	}
};