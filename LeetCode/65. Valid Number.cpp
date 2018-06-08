#include"x.h"

/*
思路：这种字符串处理的题目烦的很，corner case 太多而且题目说的也不清楚，需要注意的是下面几种case 
(.54343)这种数据是合法的，
(.)这个数据是不合法的，
323e这种数据是不合法的，e后面需要跟数字，并且还可能有符号．开头结尾可能有空格．

我们可以设置两个计数器，一个用来测试字符串是否能够按照规定的字符走完，另一个用于标记是否出现了非法的case，
比如e后面没有跟数据，或者e不能出现在首位，
因为比如：1.2e+12这种是科学计数法，表示1.2*(10^12)，所以e之前必须有数据．

*/
class Solution {
public:
	bool isNumber(string s) {
		//i记位，k统计数字
		int i = 0, k = 0, len = s.size();
		//读取字符串前面的空格，直到不为空跳出循环，读取字符
		while (s[i] == ' ') 
			i++;
		//开始读取字符串，前面可能会有+-号
		if (s[i] == '+' || s[i] == '-') 
			i++;
		//正负号判断完毕，判断后面的字符是不是数字，若是K++
		while (isdigit(s[i])) 
			i++, k++;

		if (s[i] == '.') 
			i++;
		while (isdigit(s[i])) 
			i++, k++;
		if (k == 0) 
			return false;//小数点前后没有数字，(.)不合法
		//小数点后面的连续数字判断完毕，直到遇到非法数字，比如e，
		//の的后面肯定不会出现小数
		if (s[i] == 'e')
		{
			i++, k = 0;
			if (s[i] == '+' || s[i] == '-') 
				i++;
			while (isdigit(s[i])) 
				i++, k++;
			if (k == 0) 
				return false;
		}
		while (s[i] == ' ') 
			i++;
		return i == len;//没有走完，即中途通过上述方法判断出了false已跳出程序，若是数字串的话，会全部遍历完，i==len.
	}
};



//？看不懂
class Solution {
public:
	bool isNumber(const string& s) {
		enum InputType {
			INVALID, // 0
			SPACE, // 1
			SIGN, // 2
			DIGIT, // 3
			DOT, // 4
			EXPONENT, // 5
			NUM_INPUTS // 6
		};
		//二维数组
		const int transitionTable[][NUM_INPUTS] = {
			-1, 0, 3, 1, 2, -1, // next states for state 0
			-1, 8, -1, 1, 4, 5, // next states for state 1
			-1, -1, -1, 4, -1, -1, // next states for state 2
			-1, -1, -1, 1, 2, -1, // next states for state 3
			-1, 8, -1, 4, -1, 5, // next states for state 4
			-1, -1, 6, 7, -1, -1, // next states for state 5
			-1, -1, -1, 7, -1, -1, // next states for state 6
			-1, 8, -1, 7, -1, -1, // next states for state 7
			-1, 8, -1, -1, -1, -1, // next states for state 8
		};
		int state = 0;
		for (auto ch : s) {
			InputType inputType = INVALID;
			if (isspace(ch))
				inputType = SPACE;
			else if (ch == '+' || ch == '-')
				inputType = SIGN;
			else if (isdigit(ch))
				inputType = DIGIT;
			else if (ch == '.')
				inputType = DOT;
			else if (ch == 'e' || ch == 'E')
				inputType = EXPONENT;
			// Get next state from current state and input symbol
			state = transitionTable[state][inputType];
			// Invalid input
			if (state == -1) return false;
		}
		// If the current state belongs to one of the accepting (final) states,
		// then the number is valid
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};