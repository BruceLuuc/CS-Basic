#include"x.h"

class Solution_134_1 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		
		for (int i = 0; i != gas.size(); ++i)
		{
			int j = i;
			int curgas = gas[i];

			while (curgas >= cost[j])
			{
				curgas -= cost[j];
				j = (j + 1) % gas.size();
				if (j == i) return i;
				curgas += gas[j];
			}
		}

		return -1;

	}
};


class Solution_134_2 {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int total = 0;
		int j = -1;
		for (int i = 0, sum = 0; i < gas.size(); ++i) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0) {
				j = i;
				sum = 0;
			}
		}
		return total >= 0 ? j + 1 : -1;
	}
};