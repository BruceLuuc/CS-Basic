#include"x.h"

class Solution_105_1 {
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder),begin(inorder), end(inorder));
	}

	template<typename T>
	TreeNode* buildTree(T pre_first, T pre_last,T in_first, T in_last) {
		if (pre_first == pre_last|| in_first == in_last) return nullptr;
		auto root = new TreeNode(*pre_first);
		auto RootPos = find(in_first, in_last, root->val);
		auto leftSize = distance(in_first, RootPos);

		auto boundary = next(pre_first, leftSize+1);

		root->left = buildTree(next(pre_first), boundary, in_first, RootPos);
		root->right = buildTree(boundary, pre_last, next(RootPos), in_last);
		return root;
	}
};


class Solution_105_2 {
public:
	TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
		// deal with edge case(s)
		if (preorder.size() == 0)
			return nullptr;

		stack<int> s;
		stack<TreeNode *> st;
		TreeNode *t, *r, *root;
		int i, j, f;

		f = i = j = 0;
		s.push(preorder[i]);

		root = new TreeNode(preorder[i]);
		st.push(root);
		t = root;
		i++;

		while (i<preorder.size())
		{
			if (!st.empty() && st.top()->val == inorder[j])
			{
				t = st.top();
				st.pop();
				s.pop();
				f = 1;
				j++;
			}
			else
			{
				if (f == 0)
				{
					s.push(preorder[i]);
					t->left = new TreeNode(preorder[i]);
					t = t->left;
					st.push(t);
					i++;
				}
				else
				{
					f = 0;
					s.push(preorder[i]);
					t->right = new TreeNode(preorder[i]);
					t = t->right;
					st.push(t);
					i++;
				}
			}
		}

		return root;
	}	
};


int main_105() {
	vector<vector<int>>a = {
		{ 1,2,3,4 },
	{ 5,1,2,3 },
	{ 9,5,1,2 },
	{ 7,9,5,1 },
	{ 8,7,9,5 } };

	vector<int>b = { 1,2,3,4,5,6 };
	cout << *--end(b) << endl;
	


	system("pause");
	return 0;
}