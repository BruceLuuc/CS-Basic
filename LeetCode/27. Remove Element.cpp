#include"x.h"


//�ύʧ�ܣ����г�ʱ
class Solution_27_1 {
public:
	int removeElement(vector<int>& nums, int val) {	
		int index;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (nums[i] != val)
			{
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};

class Solution_27_2 {
public:
	int removeElement(vector<int>& nums, int target) {
		return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
	}
};