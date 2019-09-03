#include"x.h"
class Solution_73_1 {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		
		const size_t m = matrix.size();//m��
		const size_t n = matrix[0].size();//n��

		//��ʼ�� ���趼û��0 ��false
		vector<bool> row(m, false); 
		vector<bool> col(n, false); 

		//����  ��0��λ���������� ���Ϊtrue
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = col[j] = true;
				}
			}
		}

		//�����һ�г���0  ��Ϊ0
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);
				//memset����ʧ�� ��fill
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

//�ȵ�һ��������
class Solution_73_2 {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();

		bool row_has_zero = false; 
		bool col_has_zero = false;
		
		//��һ���Ƿ���0
		for (size_t i = 0; i < n; i++)
			if (matrix[0][i] == 0) {
				row_has_zero = true;
				break;
			}

		//��һ���Ƿ���0
		for (size_t i = 0; i < m; i++)
			if (matrix[i][0] == 0) {
				col_has_zero = true;
				break;
			}

		for (size_t i = 1; i < m; i++)
			for (size_t j = 1; j < n; j++)
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;//0���ڵ���λ�ñ��Ϊ0  ӳ�䵽��һ��
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

	cout << "ԭʼ���飺\n";
	for (auto i : a)
	{
		print_vector(i);
	}
	cout << "\n����֮������ݣ�\n";
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
	cout << "�ķ�ʱ�䣺" << 10000*time << endl;



	system("pause");
	return 0;
}