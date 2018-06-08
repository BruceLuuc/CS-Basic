#include"x.h"

class Solution_4_1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		int len1 = nums1.size();
		int len2 = nums2.size();
		int len = len1 + len2;
		if (len & 1) {
			return findKth(nums1, 0, nums2, 0, len / 2 + 1);//奇数
		}
		return (findKth(nums1, 0, nums2, 0, len / 2) + findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2;//偶数
	}

	double findKth(vector<int>& nums1, int i1, vector<int>& nums2, int i2, int k) {
		if (i1 >= nums1.size()) {
			return nums2[i2 + k - 1];//如果num1为空
		}
		if (i2 >= nums2.size()) {
			return nums1[i1 + k - 1];//num2为空
		}
		if (k == 1) {
			return min(nums1[i1], nums2[i2]);
		}

		int key1 = i1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[i1 + k / 2 - 1];
		int key2 = i2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[i2 + k / 2 - 1];
		if (key1<key2) {
			return findKth(nums1, i1 + k / 2, nums2, i2, k - k / 2);
		}
		else {
			return findKth(nums1, i1, nums2, i2 + k / 2, k - k / 2);
		}
	}
};


class Solution_4_2 {
public:
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
		const int m = A.size();
		const int n = B.size();
		int total = m + n;
		if (total & 0x1)
			return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
		else
			return (find_kth(A.begin(), m, B.begin(), n, total / 2)
				+ find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
	}
private:
	static int find_kth(std::vector<int>::const_iterator A, int m,
		std::vector<int>::const_iterator B, int n, int k) {
		//always assume that m is equal or smaller than n
		if (m > n) return find_kth(B, n, A, m, k);
		if (m == 0) return *(B + k - 1);
		if (k == 1) return min(*A, *B);
		//divide k into two parts
		int ia = min(k / 2, m), ib = k - ia;
		if (*(A + ia - 1) < *(B + ib - 1))
			return find_kth(A + ia, m - ia, B, n, k - ia);
		else if (*(A + ia - 1) > *(B + ib - 1))
			return find_kth(A, m, B + ib, n - ib, k - ib);
		else
			return A[ia - 1];
	}
};