#include"x.h"


//分治法
class Solution_69_1 {
public:
	int mySqrt(int x) {
		if (x<2)return x;
		int left = 1;
		int right = x / 2;
		int last_mid;//记录最近一次mid

		while (left <= right) {
			const int mid = left + (right - left) / 2;
			if (x / mid>mid) {//不要使用x>mid*mid,会溢出
				last_mid = mid;
				left = mid + 1;
			}
			else if (x / mid<mid)
				right = mid - 1;
			else
				return mid;
		}
		return last_mid;
	}
};


class Solution_69_2 {
public:
	int mySqrt(int x) {
		if (x<2)return x;
		int left = 1, right = INT_MAX;
		while (true) {
			int mid = left + (right - left) / 2;
			if (mid > x / mid) {
				right = mid - 1;
			}
			else {
				if (mid + 1 > x / (mid + 1))
					return mid;
				left = mid + 1;
			}
		}
	}
};