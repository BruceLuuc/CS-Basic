#include"x.h"

//����¼��
class Solution_64_1 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		this->f = vector<vector<int>>(m, vector<int>(n, -1));//���棬��ʼ��Ϊ-1
		return dfs(grid, m - 1, n - 1);
	}
private:
	vector<vector<int>>f;
	int dfs(const vector<vector<int> > &grid, int x, int y) {
		if (x < 0 || y < 0) return INT_MAX; //Խ�磬��ֹ������ע�⣬����0
		if (x == 0 && y == 0) return grid[0][0]; //�ص���㣬��������
		return min(getOrUpdate(grid, x - 1, y),getOrUpdate(grid, x, y - 1)) + grid[x][y];
	}
	int getOrUpdate(const vector<vector<int> > &grid, int x, int y) {
		if (x < 0 || y < 0) return INT_MAX; 
		if (f[x][y] >= 0) return f[x][y];
		else return f[x][y] = dfs(grid, x, y);
	}
};

//��̬�滮
class Solution_64_2 {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0) return 0;
		const int m = grid.size();
		const int n = grid[0].size();
		vector<vector<int>>f = vector<vector<int>>(m, vector<int>(n, 0));
		//int f[m][n];
		f[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			f[i][0] = f[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; i++) {
			f[0][i] = f[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
			}
		}
		return f[m - 1][n - 1];
	}
};

//����+��������
class Solution_64_3 {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();

		vector<int> f(n,INT_MAX);//��ʼ�����飬��ΪINT_MAX
		f[0] = 0;
		for (int i = 0; i < m; i++) {
			f[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				f[j] = min(f[j - 1], f[j]) + grid[i][j];
			}
		}
		return f[n - 1];
	}
};

void main_64()
{
	//C����
	int *array = 0, num, i;
	printf("Please input the number of element: ");
	scanf_s("%d", &num);

	// ���붯̬����ʹ�õ��ڴ��   
	array = (int *)malloc(sizeof(int)*num);
	if (array == 0)             // �ڴ�����ʧ��,��ʾ�˳�   
	{
		printf("Out of memory,press any key to quit...\n");
		exit(0);             // ��ֹ��������,���ز���ϵͳ   
	}

	// ��ʾ����num������   
	printf("Please input %d elements: ", num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &array[i]);

	// ����������num������   
	printf("%d Elements are: \n", num);
	for (i = 0; i < num; i++)
		printf("%d,", array[i]);

	printf("\b \n");    // ɾ�����һ�����ֺ�ķָ�������   
	free(array);        // �ͷ���malloc����������ڴ��   


	//C++,��new������ɾ��
	int *p = nullptr;
	int size = 0;
	cout << "\nC++\nPlease input the number of element:\n";
	cin >> size;
	p = new int[size];

	cout << "Please input " << size << " elements:\n";
	for (int i = 0; i < size; i++)
		cin >> p[i];

	cout << size << " Elements are: \n";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ",";
	}

	printf("\b \n");
	delete  []p;
}