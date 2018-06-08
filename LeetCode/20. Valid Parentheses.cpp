#include"x.h"
class Solution_20_1 {
public:
	bool isValid(string s) {
		
		string left = "([{";
		string right = ")]}";

		stack<char> stk;

		for (auto c : s) {
			if (left.find(c) != string::npos) //means "until the end of the string"
			{
				stk.push(c);
			}
			else {
				if (stk.empty() || stk.top() != left[right.find(c)])
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
	}
};



class Solution_20_2 {
public:
	bool isValid(string s) {
		stack<char>stk;
		for (auto i : s) {
			if (i == '(' || i == '[' || i == '{') {
				stk.push(i);
			}
			else if (stk.empty()) {
				return false;
			}
			else {
				char top = stk.top();
				if ((top == '('&&i == ')') ||
					(top == '['&&i == ']') ||
					(top == '{'&&i == '}')) {
					stk.pop();
				}
				else {
					return false;
				}
			}
		}
		return stk.empty();
	}
};

