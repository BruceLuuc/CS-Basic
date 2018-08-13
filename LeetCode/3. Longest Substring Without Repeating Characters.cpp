#include"x.h"

class Solution_3_1 {
public:
	int lengthOfLongestSubstring(string s) {
		int last[255];
		fill__(last, last + 255, -1);//记录下标
		int start = 0;
		int len = 0;

		for (int i = 0; i != s.size(); i++) {
			if (last[s[i]] >= start) {
				len = max(len, i - start);
				start = last[s[i]] + 1;
			}
			last[s[i]] = i;//记录每一个字符的下标
		}
		return max(len, (int)s.size() - start);
	}

private:
	template <typename ForwardIterator, typename T>
	void fill__(ForwardIterator first, ForwardIterator last, const T& val) {
		while (first != last) {
			*first = val;
			++first;
		}
	}
};


//暴力 超时
class Solution_3_2 {
public:
	int lengthOfLongestSubstring(string s) {
		const int n = s.size();
		int len = 0;
		for (int i = 0; i != n; i++)
			for (int j = i + 1; j <= n; j++)
				if (allUnique(s.substr(i,j-i)))
					len = max(len, j - i);
		return len;
	}
private:
	bool allUnique(string s) {
		set<char> set(s.begin(),s.begin());
		return s.size()==set.size();
	}
};

enum etest {
	eparam1=1,
	eparam2,
	eparam3=43,
	eparam4,
	eparam5,
	eparam6
}epr;


//O(2^n)  in worst case
//https://www.geeksforgeeks.org/longest-common-subsequence/
class Solution_LCS_1 {
public:
	vector<vector<int>>f;
	int LCS(string s1, string s2) {
		const int m=s1.size()+1; 
		const int n=s2.size()+1;

		f=vector<vector<int>>(m, vector<int>(n,-1));
		return __LCS(s1, s2);
	}
private:
	int __LCS(string s1, string s2) {
		const int len1 = s1.size();
		const int len2 = s2.size();

		if (f[len1][len2] != -1)
			return f[len1][len2];
		if (len1 == 0 || len2 == 0) {
			f[0][0] = 0;
			return 0;
		}			
		if (s1[len1 - 1] == s2[len2 - 1]) {
			f[len1][len2] = 1 + LCS(s1.substr(0, len1 - 1), s2.substr(0, len2 - 1));
			return f[len1][len2];
		}
		else {
			f[len1][len2]= max(LCS(s1, s2.substr(0, len2 - 1)), LCS(s1.substr(0, len1 - 1), s2));
			return f[len1][len2];
		}
			
	}


};
int LCS(string s1, string s2) {
	const int len1 = s1.size();
	const int len2 = s2.size();
	if (len1 == 0 || len2 == 0)
		return 0;
	if (s1[len1 - 1] == s2[len2 - 1])
		return 1 + LCS(s1.substr(0, len1 - 1), s2.substr(0, len2 - 1));
	else
		return max(LCS(s1, s2.substr(0, len2 - 1)), LCS(s1.substr(0, len1 - 1), s2));
}

// O(mn)
int LCS_2(string s1, string s2) {
	const int m = s1.size();
	const int n = s2.size();
	vector<vector<int>>L(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;		
			else
				L[i][j]= max(L[i][j - 1], L[i - 1][j]);
		}
	return L[m][n];
}


int main() {
//Y:  char c;
//	scanf_s("%c", &c);
//	switch (c){
//	case'1':printf("1"); break;
//	case'2':printf("2"); break;
//	case'3':printf("3"); break;
//	default:printf("即可很快就"); break;
//	}
//	cout << endl;

	//char c1, c2;
	//int a1, a2;
	//c1 = getchar();//'1'
	//scanf_s("%2d", &a1);//2
	//c2 = getchar();//a
	//scanf_s("%3d", &a2);//345
	//printf("%c,%d,%c,%d", c1,a1,c2,a2);//12a345b789

	//cin.clear();
	//int a[3][5] = { {2,3,4,5,6},{7,8,9,10,11},{11,22,33,44,55} };
	//int *ptr = (int*)(&a + 1);
	//cout << *(ptr-1) << endl;

	//int *ptr1 = (int*)(&a);
	//cout << *(ptr1) << endl;

	//printf("%d, %d", eparam4,eparam6);
	//cout << endl;


	//int  aa[3] = { 0 }, i=0,j=0, k = 2;
	//for (; i < k; i++)
	//	for (j=0; j < k; j++)
	//		aa[j] = aa[i] + 1;

	//cout <<"a[1]=" <<aa[1] << "\n\n\n";


	//char str[] = "ab\n\\n";
	//const int n = strlen(str);
	//cout << strlen(str) << endl;
	//for (int i = 0; i != n; i++)
	//	cout << str[i]<<" ";

	//cout << "\n>" << "\48" << " <" << endl;

	//char a11 = '1';
	//char b11 = '2';
	//printf("%c", b11++);
	//printf("%d\n", b11 - a11);

	//etest aaa = eparam2;

	//if (aaa == eparam2)
	//	cout << "Fuck!\n";

	//char c;
	//while ((c = getchar()) != '\n'){
	//	if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z'){
	//		c = c + 4;
	//		if (c>'Z' && c <= 'Z' + 4 || c>'z')
	//			c = c - 26;
	//	}
	//	std::cout << c;
	//}
	//std::cout << std::endl;

	//const char *pppp ="hello";

	string s1 = "AGGTABSDFSDFGSDGD";
	string s2 = "GXTXAYBSGFSDGFSDF";
	clock_t startTime = clock();
	cout << LCS_2(s1, s2) << endl;
	clock_t endTime = clock();
	cout << "花费时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "秒。\n";

	while (1);
	return 0;
}

