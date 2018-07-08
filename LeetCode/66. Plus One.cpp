#include"x.h"

class Solution_66_1 {
public:
	vector<int> plusOne(vector<int>& digits) {
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>&digits, int one) {
		int carry = one;
		for (auto i = digits.rbegin(); i != digits.rend(); ++i) {
			*i += carry;
			carry = *i / 10;
			*i %= 10;
		}
		if (carry > 0)
			digits.insert(digits.begin(), 1);

	}
};

class Solution_66_2 {
public:
	vector<int> plusOne(vector<int>& digits) {
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>&digits, int one) {
		int carry = one;
		for_each (digits.rbegin(), digits.rend(), [&carry](int &i) {
			i += carry;
			carry = i / 10;
			i %= 10;//最终i保留的大小
		});
		if (carry > 0)
			digits.insert(digits.begin(), 1);

	}
};

int main() {
	Solution_66_2 A;
	vector<int>a = { 9,9,9 };
	a= A.plusOne(a);
	for (auto i : a)
		cout << i << " ";
	cout << endl;

	for_each(a.begin(), a.end(), [](int &i) {cout << i << ","; });



	while (1);
	return 0;
}