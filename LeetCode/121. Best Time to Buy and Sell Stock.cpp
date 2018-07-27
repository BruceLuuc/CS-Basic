#include"x.h"


//只能进行一次交易
//贪心法，找到价格最低和最高的一天  低进高出
class Solution_121 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)return 0;
		int profit = 0;
		int cur_min = prices[0];

		for (int i = 1; i != prices.size(); ++i) {
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]);//保证最小的始终在前面
		}
		return profit;
	}
};