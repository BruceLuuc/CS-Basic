#include"x.h"

class Solution_74 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())return false;
		const size_t m = matrix.size();
		const size_t n = matrix.front().size();
		if (m==0||n==0||target<matrix[0][0] || target>matrix[m - 1][n - 1])return false;

		int first = 0;
		int last = m * n;
		while (first < last) {
			int mid = first + (last - first) / 2;
			int val = matrix[mid / n][mid%n];
			if (val == target)
				return true;
			else if (val < target)
				first = ++mid;
			else
				last = mid;
		}
		return false;
	}
};