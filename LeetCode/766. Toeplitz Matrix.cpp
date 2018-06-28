#include"x.h"


//太简单了！不值一提！
class Solution_766 {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix.size() == 1 || matrix[0].size() == 1)return true;
		const int m = matrix.size();
		const int n = matrix[0].size();

		//扫描第一行
		for (int i = 0; i != n - 1; ++i) {
			for (int j = i + 1, k = 1; j != n && k != m; ++j, ++k) {
				if (matrix[0][i] != matrix[k][j])
					return false;
			}
		}

		//扫描第一列
		for (int i = 0; i != m - 1; ++i) {
			for (int j = i + 1,  k = 1; j != m && k != n; ++j, ++k) {
				if (matrix[i][0] != matrix[j][k])
					return false;
			}
		}

		return true;

	}
};



int main_766() {
	vector<vector<int>>a = { 
	{1,2,3,4},
	{5,1,2,3},
	{9,5,1,2},
	{7,9,5,1},
	{8,7,9,5}};
	Solution_766 A;
	cout << "是否为真？";
	cout << std::boolalpha <<A.isToeplitzMatrix(a)<<endl;


	system("pause");
	return 0;
}