#include"x.h"

class Solution_79_1 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		const int m = board.size();
		const int n = board[0].size();
		vector<vector<bool>>visited(m, vector<bool>(n, false));
		for (int i = 0; i != m; i++)
			for (int j = 0; j != n; j++)
				if (dfs(board, word, 0, i, j, visited))
					return true;
		return false;
	}
private:
	static bool dfs(const vector<vector<char>>& board, string& word, int index, int x, int y, vector<vector<bool>> &visited) {
		if (index == word.size())return true;//收敛条件
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())return false;//越界，终止
		if (visited[x][y])return false;//已经访问，剪枝
		if (board[x][y] != word[index])return false;//不相等 剪枝

		visited[x][y] = true;
		bool ret = 
			dfs(board, word, index + 1, x - 1, y, visited) ||
			dfs(board, word, index + 1, x + 1, y, visited) ||
			dfs(board, word, index + 1, x, y - 1, visited) ||
			dfs(board, word, index + 1, x, y + 1, visited);
		visited[x][y] = false;//修改回来  递归到底完毕后  下一入口重新搜索时 visited重新全部置false  重新找路径
		return ret;
	}
};


// Backtracking implmentation
class Solution_79_2 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				if (adjacentSearch(board, word, i, j, 0))
					return true;
		return false;
	}
protected:
	bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index){
		if (index == word.size()) return true; // end condition
		if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) return false; // boundary of matrix
		if (board[i][j] != word[index]) return false; // do not match
													  // match!
		board[i][j] = '*'; // change the content, to avoid duplicated search
		bool furtherSearch = 
			adjacentSearch(board, word, i + 1, j, index + 1) || // up
			adjacentSearch(board, word, i - 1, j, index + 1) || // down
			adjacentSearch(board, word, i, j - 1, index + 1) || // left
			adjacentSearch(board, word, i, j + 1, index + 1);   // right

		board[i][j] = word[index]; // modify it back!
		return furtherSearch;
	}
};