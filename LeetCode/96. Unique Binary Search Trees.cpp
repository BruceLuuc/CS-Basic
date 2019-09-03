#include"x.h"

class Solution_96_1 {
public:
	int numTrees(int n) {
		vector<int> f(n + 1, 0);
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int k = 1; k <= i; ++k)
				f[i] += f[k - 1] * f[i - k];
		}
		return f[n];
	}
};

int main_96()
{
	Solution_96_1 A;

	cout << A.numTrees(3) << endl;


	system("pause");
	return 0;
}