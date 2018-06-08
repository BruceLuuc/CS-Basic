#include"x.h"


class Solution_43_1 {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		const int m = num1.size();
		const int n = num2.size();

		vector<int> pos(m + n, 0);
		string result;

		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				int mul = (num1[i] - '0')*(num2[j] - '0');
				int carry = i + j;
				int p = i + j + 1;
				int sum = mul + pos[p];//�@һ����p�ஔ���һ����tmp�����ͼ����Mλ�Ĕ�Ŀ

				
				pos[carry] += sum / 10;//����10������һλ
				pos[p] = sum % 10;
			}
		}

		int i = 0;
		while (pos[i] == 0)++i;//���ǰ���0	
		for (; i != m + n; ++i) {
			result.push_back(pos[i] + '0');//�D�Q��char
		}
		return result;
	}
};

//���M���������㷨��������⡣�Ƚy�y�ۼӵ�λ���棬������ᵽǰ�Mλ
class Solution_43 {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		int len1 = num1.length(), len2 = num2.length();

		vector<int> temp(len1 + len2, 0);

		for (int i = 0; i < len1; ++i) {
			int d1 = num1[i] - '0';
			for (int j = 0; j < len2; ++j) {
				int d2 = num2[j] - '0';
				temp[i + j + 1] += d1 * d2;
			}
		}

		for (auto ritr = temp.rbegin(); ritr != prev(temp.rend()); ++ritr) {
			*next(ritr) += *ritr / 10;//����λ���ۼӵ�ǰ��
			*ritr %= 10;//ֻ��λ
		}


		string res;
		res.reserve(temp.size());
		//������������Ԫ�� Ȼ��ִ��һ������
		std::transform(temp.cbegin(), temp.cend(), back_inserter(res), [](int d) { return d + '0'; });		
		int posNonzero = res.find_first_not_of('0');
		return res.substr(posNonzero);
	}
};

/*
֪�R�c��
reserveֻ��ȷ���пռ��ܹ���������x��Ԫ��
���ǲ�û�����Ϊ������ַ�ռ䣬��v[0]��v[1]���и�ֵ��û������ģ���Щ�ڴ�ռ��ʱ�������ǡ�Ұ�ġ�


��Lambda���ʽ�� ������������
���@�б�ͨ�����[]
auto f=[]{return 42;};
cout<<f()<<endl;//��ӡ42

[capture list] (params list) -> return type {function body}
capture list] (params list) {function body}

sort(v.begin(), v.end(), [](int a, int b) -> bool { return a < b; });   // Lambda���ʽ

*/


//����1
typedef vector<int> bigint;
bigint make_bigint(string const& repr) {
	bigint n;
	transform(repr.rbegin(), repr.rend(), back_inserter(n),[](char c) { return c - '0'; });
	return n;
}
string to_string(bigint const& n) {
	string str;
	transform(find_if(n.rbegin(), prev(n.rend()),[](char c) { return c > '\0'; }), n.rend(), back_inserter(str),
		[](char c) { return c + '0'; });
	return str;
}
bigint operator*(bigint const& x, bigint const& y) {
	bigint z(x.size() + y.size());
	for (size_t i = 0; i < x.size(); ++i)
		for (size_t j = 0; j < y.size(); ++j) {
			z[i + j] += x[i] * y[j];
			z[i + j + 1] += z[i + j] / 10;
			z[i + j] %= 10;
		}
	return z;
}
class Solution_43_2 {
public:
	string multiply(string num1, string num2) {
		return to_string(make_bigint(num1) * make_bigint(num2));
	}
};



