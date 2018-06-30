#include"x.h"


class Solution_147 {
public:
	ListNode * insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)return head;
		//创建一个系统最小节点
		ListNode dummy(INT_MIN);
		for (ListNode*cur = head; cur;) {
			auto pos = findInsertPos(&dummy, cur->val);
			//把cur节点插入pos节点之后
			ListNode*tmp = cur->next;
			cur->next = pos->next;
			pos->next = cur;
			cur = tmp;
		}
		return dummy.next;
	}
	ListNode*findInsertPos(ListNode*head, int x) {
		ListNode*pre = nullptr;
		for (ListNode*cur = head; cur&&cur->val <= x; pre = cur, cur = cur->next);
		return pre;
	}
};