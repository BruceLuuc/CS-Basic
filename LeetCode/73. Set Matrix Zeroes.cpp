#include"x.h"
class Solution_73_1 {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		
		const size_t m = matrix.size();//m行
		const size_t n = matrix[0].size();//n列

		//初始化 假设都没有0 即false
		vector<bool> row(m, false); 
		vector<bool> col(n, false); 

		//遍历  把0的位置所在行列 标记为true
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = col[j] = true;
				}
			}
		}

		//如果这一行出现0  置为0
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);
				//memset置零失败 用fill
		}

		for (size_t j = 0; j < n; ++j) {
			if (col[j]) {
				for (size_t i = 0; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

//比第一个方法慢
class Solution_73_2 {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();

		bool row_has_zero = false; 
		bool col_has_zero = false;
		
		//第一行是否有0
		for (size_t i = 0; i < n; i++)
			if (matrix[0][i] == 0) {
				row_has_zero = true;
				break;
			}

		//第一列是否有0
		for (size_t i = 0; i < m; i++)
			if (matrix[i][0] == 0) {
				col_has_zero = true;
				break;
			}

		for (size_t i = 1; i < m; i++)
			for (size_t j = 1; j < n; j++)
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;//0所在的行位置标记为0  映射到第一行
					matrix[i][0] = 0;
				}

		for (size_t i = 1; i < m; i++)
			for (size_t j = 1; j < n; j++)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;

		if (row_has_zero)
			for (size_t i = 0; i < n; i++)
				matrix[0][i] = 0;

		if (col_has_zero)
			for (size_t i = 0; i < m; i++)
				matrix[i][0] = 0;
	}
};









int main_73()
{
	vector<vector<int> >a = {
	{ 0,1,2,0 },
	{ 3,4,5,2 },
	{ 1,3,1,5 },
	{ 1,1,1,1 }
	};

	cout << "原始数组：\n";
	for (auto i : a)
	{
		print_vector(i);
	}
	cout << "\n处理之后的数据：\n";
	Solution_73_2 A;

	clock_t startTime = clock();
	A.setZeroes(a);
	//Sleep(1000);
	clock_t endTime = clock();

	for (auto i : a)
	{
		print_vector(i);
	}
	double time = double(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "耗费时间：" << 10000*time << endl;



	system("pause");
	return 0;
}