#include"x.h"

class Solution_120_1 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		const int m = triangle.size();
		if (m == 0)return 0;
		if (m == 1)return triangle[0][0];
		
		for (int i = m-2; i >=0; --i) {
			for (int j = 0; j != i+1; ++j) {
				triangle[i][j] = min(triangle[i + 1][j], triangle[i +1][j+1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};