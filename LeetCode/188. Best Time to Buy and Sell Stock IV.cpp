#include"x.h"


//看不懂
class Solution_188 {
public:
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (n < 2)return 0;
		if (k >= n/2)return Profit(prices);

		vector<int>local(k+1, 0);//局部最优解  max(最后一天一定进行交易卖出
		vector<int>global(k+1, 0);

		for (int i = 0; i < n - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; --j) {
				local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
				global[j] = max(global[j], local[j]);
			}
		}
		return global[k];
	}


private:
	//k大于n时  即不限次数的情况  #122
	int Profit(vector<int>& prices) {
		const int n = prices.size();
		if (n < 2)return 0;
		int sum = 0;
		for (int i = 1; i != n; ++i) {
			sum += max(prices[i] - prices[i - 1], 0);
		}
		return sum;
	}
};