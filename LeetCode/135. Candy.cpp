#include"x.h"

class Solution_135_1 {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> increment(n);
		for (int i = 1, inc = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;
		}
		for (int i = n - 2, inc = 1; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				increment[i] = max(inc++, increment[i]);
			else
				inc = 1;
		}
		return accumulate(&increment[0], &increment[0] + n, n);
	}
};

//Ê§°Ü
class Solution_135_2 {
public:
	int candy(vector<int>& ratings) {
		int sums = 0;
		int len = ratings.size();
		if (len == 1)return 1;

		vector<int>vec(len, 1);
		for (int i = 1; i != len; ++i) {
			if (ratings[i] > ratings[i - 1])vec[i] = vec[i - 1] + 1;
		}

		for (int i = len - 2; i >= 0; --i){
			if (ratings[i] > ratings[i + i] && vec[i] <= vec[i + 1])
				vec[i] = vec[i + 1] + 1;
		}

		for (auto i : vec){
			sums += i;
		}
		return sums;
	}
};