#include"x.h"

class Solution_24_1 {
public:
	ListNode * swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode dummy(-1);
		dummy.next = head;

		for (ListNode *pre = &dummy, *cur = head, *next = head->next; 
			next; 
			pre = cur, cur = cur->next, next = cur ? cur->next : nullptr) 
		
		{
			pre->next = next;
			cur->next = next->next;
			next->next = cur;
		}
		return dummy.next;
	}
};


class Solution_24_2 {
public:
	ListNode * swapPairs(ListNode* head) {
		ListNode* p = head;
		while (p && p->next) {
			swap(p->val, p->next->val);
			p = p->next->next;
		}
		return head;
	}
};
