#include"x.h"

ListNode* create_List() {
	auto g = new ListNode(7);
	auto f = new ListNode(6, g);
	auto e = new ListNode(5, f);
	auto d = new ListNode(4, e);
	auto c = new ListNode(3, d);
	auto b = new ListNode(2, c);
	auto a = new ListNode(1, b);
	return a;
}