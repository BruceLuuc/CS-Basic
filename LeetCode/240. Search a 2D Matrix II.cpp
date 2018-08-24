#include"x.h"

class Solution_240 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())return false;
		const int m = matrix.size();
		const int n = matrix[0].size();

		int row = 0;
		int col = n - 1;
		while (row < m&&col >= 0) {
			int tmp = matrix[row][col];
			if (target == tmp)
				return true;
			else if (target < tmp)
				col--;
			else
				row++;
		}
		return false;
	}
};