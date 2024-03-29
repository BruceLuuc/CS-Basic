﻿#include"x.h"
class Solution_48 {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();

		for (int i = 0; i != n; i++)
			for (int j = 0; j != n - i; j++)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

		for (int i = 0; i != n / 2; i++)
			for (int j = 0; j != n; j++)
				swap(matrix[i][j], matrix[n - 1 - i][j]);

	}
};