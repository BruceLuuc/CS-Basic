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
				int sum = mul + pos[p];//這一步的p相當於上一步的tmp，總和加上進位的數目

				
				pos[carry] += sum / 10;//大于10的数进一位
				pos[p] = sum % 10;
			}
		}

		int i = 0;
		while (pos[i] == 0)++i;//祛除前面的0	
		for (; i != m + n; ++i) {
			result.push_back(pos[i] + '0');//轉換成char
		}
		return result;
	}
};

//改進，比上面算法更容易理解。先統統累加到位上面，最後從後到前進位
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
			*next(ritr) += *ritr / 10;//砍掉個位，累加到前面
			*ritr %= 10;//只留個位
		}


		string res;
		res.reserve(temp.size());
		//遍历容器里面元素 然后执行一个操作
		std::transform(temp.cbegin(), temp.cend(), back_inserter(res), [](int d) { return d + '0'; });		
		int posNonzero = res.find_first_not_of('0');
		return res.substr(posNonzero);
	}
};

/*
知識點：
reserve只是确保有空间能够放下至少x个元素
但是并没有真的为其分配地址空间，对v[0]、v[1]进行赋值是没有意义的，这些内存空间此时可能仍是‘野的’


“Lambda表达式” “匿名函数”
捕獲列表通常為空[]
auto f=[]{return 42;};
cout<<f()<<endl;//打印42

[capture list] (params list) -> return type {function body}
capture list] (params list) {function body}

sort(v.begin(), v.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式

*/


//代码1
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



