#include"x.h"


//最多进行两次交易（0次、1次都是可以的）  买入之前必须卖出
//f[i]表示区间[0.i]上最大利润，从前往后按#121题求取即可
//g[i]表示区间[i,n)上的最大利润
//===============然后相加取最大值即可==============
class Solution_123 {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		if (n < 2)return 0;
	
		vector<int>f(n, 0);
		vector<int>g(n, 0);

		for (int i = 1, valley = prices[0]; i != n; ++i) {
			valley = min(valley, prices[i]);//先计算valley,即允许同一天内买进卖出
			f[i] = max(f[i - 1], prices[i] - valley);
		}

		for (int i = n - 2,peak=prices[n-1]; i >= 0; --i) {
			peak = max(peak, prices[i]);
			g[i] = max(g[i + 1], peak - prices[i]);
		}

		int max_profit = 0;
		for (int i = 0; i != n; ++i) {
			max_profit = max(max_profit,f[i]+g[i]);
		}
		return max_profit;
	}
};