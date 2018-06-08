#include"x.h"

class Solution_19_2 {
public:
	ListNode * removeNthFromEnd(ListNode *head, int n) {
		ListNode dummy{ -1, head };
		ListNode *p = &dummy, *right = &dummy;

		for (int i = 0; i < n; i++)
			right = right->next;
		while (right->next) {
			p = p->next;
			right = right->next;
		}

		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		return dummy.next;
	}
};
