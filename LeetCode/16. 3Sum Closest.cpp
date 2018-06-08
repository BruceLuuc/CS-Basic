#include"x.h"

class Solution_16_1 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = INT_MAX;
		sort(nums.begin(), nums.end());
		for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
			auto b = next(a);
			auto c = prev(nums.end());
			while (b < c) 
			{
				const int sum = *a + *b + *c;
				const int tmp_gap = abs(sum - target);
				if (tmp_gap < min_gap) 
				{
					result = sum;
					min_gap = tmp_gap;//������Сgap�ƽ�target
				}
				//�������ܺ�û�и��ӱƽ�target������һ���ж�����������
				//���򲻸�����Сgap����ʼ���Ҽб�
				if (sum < target) ++b;
				else --c;
			}
		}
		return result;
	}
};