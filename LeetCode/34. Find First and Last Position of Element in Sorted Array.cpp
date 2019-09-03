#include"x.h"


//暴力检索  O(N)  
class Solution_34_1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)return { -1,-1 };
		if (target<nums[0] || target>nums[nums.size() - 1])return { -1,-1 };


		int k = -1;
		int h = -1;

		for (int i = 0; i != nums.size(); ++i) {
			if (nums[i] == target) {
				k = i;
				break;
			}
		}

		if (k == nums.size() - 1) {
			return { k,k };
		}

		for (int i = k + 1; k != nums.size(); i++) {
			if (nums[i] != target) {
				h = i - 1;
				break;
			}
		}

		return { k,h };
	}
};

//调用STL
class Solution_34_2 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)return { -1,-1 };
		if (target<nums[0] || target>nums[nums.size() - 1])return { -1,-1 };
		const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
		const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
		if (nums[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};



//自己实现一遍STL
class Solution_34_3 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)return { -1,-1 };
		if (target<nums[0] || target>nums[nums.size() - 1])return { -1,-1 };
		const int l = distance(nums.begin(), _lower_bound(nums.begin(), nums.end(), target));
		const int u = distance(nums.begin(), prev(_upper_bound(nums.begin(), nums.end(), target)));
		if (nums[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
private:
	template <typename ForwardIterator, typename T>
	ForwardIterator _lower_bound(ForwardIterator first, ForwardIterator last, const T& val){
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count, step;
		count = distance(first, last);//返回元素个数
		while (count>0){
			it = first; 
			step = count / 2; 
			advance(it, step);//it=it+step
			//找到第一个等于val的迭代器
			if (*it<val) {   // or: if (comp(*it,val))
				first = ++it;
				count -= step + 1;
			}else 
				count = step;
		}
		return first;
	}

	template <typename ForwardIterator, typename T>
	ForwardIterator _upper_bound(ForwardIterator first, ForwardIterator last, const T& val){
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count, step;
		count = distance(first, last);
		while (count>0){
			it = first; 
			step = count / 2; 
			advance(it, step);
			//找到第一个不大于val的迭代器
			if (*it<=val) {//if (!(val < *it))
				first = ++it;
				count -= step + 1;
			}else
				count = step;
		}
		return first;
	}
};



class Solution_34_4 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)return { -1,-1 };
		if (target<nums[0] || target>nums[nums.size() - 1])return { -1,-1 };

		const int l = distance(nums.begin(), _lower_bound(nums.begin(), nums.end(), target));
		const int u = distance(nums.begin(), prev(_upper_bound(nums.begin(), nums.end(), target)));
		if (nums[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
private:

	template<typename ForwardIterator, typename T>
	ForwardIterator _lower_bound(ForwardIterator first, ForwardIterator last, T val) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (val > *mid)first = ++mid;
			else last = mid;
		}
		return first;
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator _upper_bound(ForwardIterator first, ForwardIterator last, T val) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (val >= *mid)first = ++mid;
			else last = mid;
		}
		return first;
	}
};