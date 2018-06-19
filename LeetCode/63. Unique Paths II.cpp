#include"x.h"

class Solution_63_1 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])return 0;

		vector<int>f(n, 0);
		f[0] = 1;


		for (int i = 0; i != m; ++i) {
			//先判断每一行的第一个
			//if (obstacleGrid[i][0] == 1)
			//	f[0] = 0;
			//else
			//	f[0] = f[0];

			if (f[0] == 0)
				f[0] = 0;
			else if (obstacleGrid[i][0] == 1)
				f[0] = 0;
			else
				f[0] = 1;


			for (int j = 1; j != n; ++j) {
				if (obstacleGrid[i][j] == 1)
					f[j] = 0;
				else
					f[j] = f[j] + f[j - 1];
			}
		}
		return f[n - 1];
	}
};

//优化一下代码
class Solution_63_2 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])return 0;

		vector<int>f(n, 0);
		f[0] = 1;


		for (int i = 0; i != m; ++i) {
			f[0] = f[0] == 0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
			for (int j = 1; j != n; ++j) {
				f[j] = obstacleGrid[i][j] ? 0 : f[j] + f[j - 1];
			}
		}
		return f[n - 1];
	}
};


class Solution_63_3 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		if (m <= 0)return 0;
		const int n = obstacleGrid[0].size();
		if (n <= 0)return 0;
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])return 0;

		int f[101][101];
		f[0][0] = 1;
		//初始化第一行
		for (int i = 1; i != n; ++i) {
			if (obstacleGrid[0][i] == 1) {
				f[0][i] = 0;
			}
			else {
				f[0][i] = f[0][i-1];
			}
		}

		//初始化第一列
		for (int j = 1; j != m; ++j) {
			if (obstacleGrid[j][0] == 1) {
				f[j][0] = 0;
			}
			else {
				f[j][0] = f[j-1][0];
			}
		}



		for (int i = 1; i != m; ++i) {
			for (int j = 1; j != n; ++j) {
				if (obstacleGrid[i][j] == 1)
					f[i][j] = 0;
				else
					f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}

		return f[m - 1][n - 1];


	}
};

//深搜  缓存
class Solution_63_4 {
public:
	int uniquePathsWithObstacles(const vector<vector<int> >& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
		f = vector<vector<int> >(m, vector<int>(n, 0));
		f[0][0] = 1;

		return dfs(obstacleGrid, m - 1, n - 1);
	}
private:
	vector<vector<int> > f; // 缓存
	// @return 从(0, 0) 到(x, y)的路径总数
	int dfs(const vector<vector<int> >& obstacleGrid,int x, int y) {
		if (x < 0 || y < 0) return 0; //数据非法，终止条件
		// (x,y) 是障碍
		if (obstacleGrid[x][y]) return 0;
		if (x == 0 and y == 0) return f[0][0];//回到起点，收敛条件
		if (f[x][y] > 0) {
			return f[x][y];
		}
		else {
			return f[x][y] = dfs(obstacleGrid, x - 1, y) +
				dfs(obstacleGrid, x, y - 1);
		}
	}
};