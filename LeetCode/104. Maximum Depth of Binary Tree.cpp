#include"x.h"

class Solution_104 {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};