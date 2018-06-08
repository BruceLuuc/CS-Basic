#include"x.h"




//手写了一遍，发现个别语法错误，仔细琢磨，修正之后，打开LeetCode白板一顿写！提交，失败...
//发现几处拼写错误。。语法错误。。return用的->,看来还要多实践，很多坑隐藏在实际的编程细节中，单单有思路是不够的
//把经典的基础题慢慢吃透很重要，一步一个脚印慢慢巩固
class Solution_2_1 {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		//注意：创建的是对象，不是指针，return语句中用.next访问下一个节点
		//也可以这样：
		//ListNode *dummy = new ListNode(-1);//return结果就可以这样写了 dummy->next;
		//ListNode *prev = dummy;
		ListNode dummy(-1); 
		int carry = 0;//记录是否有进位
		ListNode *prev = &dummy;
		//因为是反过来存进去链表的，第一个节点是个位，第二个节点存十位
		//所以从头开始遍历即可，结果也是反序存入
		for (ListNode *pa = l1, *pb = l2;
			pa != nullptr || pb != nullptr;
			pa = pa == nullptr ? nullptr : pa->next,
			pb = pb == nullptr ? nullptr : pb->next,
			prev = prev->next) {
			const int ai = pa == nullptr ? 0 : pa->val;
			const int bi = pb == nullptr ? 0 : pb->val;
			const int value = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;//和大于10，进位，累积到下一个循环
			prev->next = new ListNode(value); 
		}
		if (carry > 0)
			prev->next = new ListNode(carry);
		return dummy.next;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main_2() {
	string line;
	while (getline(cin, line)) {
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution_2_1().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	system("pause");
	return 0;
}