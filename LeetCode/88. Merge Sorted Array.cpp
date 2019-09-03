#include"x.h"

class Solution_88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ia = m - 1, ib = n - 1, cur = m + n - 1;
		while (ia >= 0 && ib >= 0)
			nums1[cur--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];

		while (ib >= 0)
			nums1[cur--] = nums2[ib--];

	}
};