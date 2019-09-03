#include"x.h"

class Solution_106 {
public:
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}
	template<typename T>
	TreeNode* buildTree(T in_first, T in_last, T post_first, T post_last) {
		if (in_first == in_last || post_first == post_last)return nullptr;
		const int val = *prev(post_last);
		TreeNode *root = new TreeNode(val);
		auto rootPos = find(in_first, in_last, val);
		auto leftsize = distance(in_first, rootPos);

		auto boundary = next(post_first, leftsize);

		root->left = buildTree(in_first, rootPos, post_first, boundary);
		root->right = buildTree(next(rootPos), in_last, boundary, prev(post_last));

		return root;


	}
};