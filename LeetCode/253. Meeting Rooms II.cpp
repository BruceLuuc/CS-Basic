#include"x.h"


//  Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), 
//	find the minimum number of conference rooms required.
//
//	For example,
//	Given[[0, 30], [5, 10], [15, 20]],
//	return 2.


struct Interval {  
	int start; 
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution_253 {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		map<int, int> hash;
		for (auto val : intervals)
			hash[val.start]++, hash[val.end]--;
		int ans = 0, sum = 0;
		for (auto val : hash)
			sum += val.second, ans = max(ans, sum);
		return ans;
	}
};



class Solution_253_2 {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		vector<int>times;
		for (int i = 0; i < intervals.size(); i++) {
			times.push_back(intervals[i].start);
			times.push_back(-intervals[i].end);
		}
		sort(times.begin(), times.end(), cmp);
		int minNumber = 0;
		int cur = 0;
		for (int i = 0; i < times.size(); i++) {
			if (times[i] >= 0) {
				cur++;
				minNumber = max(minNumber, cur);
			}
			else
				cur--;
		}
		return minNumber;
	}
private:
	static bool cmp(int i1, int i2) {
		if (abs(i1) == abs(i2))
			return i1 < i2;
		return abs(i1) < abs(i2);
	}
};