#include"x.h"


//不限交易次数 但是手里只能有一笔交易  下次买入前必须卖掉现有的股票
//贪心法 低进高出 把所有正的价格 差价 相加起来
//===========合计差价===========
class Solution_122 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)return 0;
		int sum = 0;
		for (int i = 1; i != prices.size(); ++i) {
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
				sum += diff;
		}
		return sum;
	}
};