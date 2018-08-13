#include"x.h"

class Solution_200 {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())return 0;
		const int m = grid.size();
		const int n = grid[0].size();

		int cnt = 0;
		for (int i = 0; i != m; i++)
			for (int j = 0; j != n; j++)
				if (grid[i][j] == '1') {
					cnt++;
					DFS(grid, i, j);
				}
		return cnt;
	}

private:
	void DFS(vector<vector<char>>& grid, int i, int j) {
		if (i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')return;
		grid[i][j] = '2';

		DFS(grid, i + 1, j);
		DFS(grid, i - 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i, j - 1);
	}

};