#include"x.h"

class Solution_23 {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)return nullptr;

		ListNode*p = lists[0];
		//从上到下滚雪球
		for (int i = 1; i != lists.size(); ++i)
			p = mergeTwoLists(p, lists[i]);
		return p;
	}
	ListNode*mergeTwoLists(ListNode*l1, ListNode*l2) {
		ListNode dummy(-1);
		ListNode *p = &dummy;
		while (l1&&l2) {
			if (l1->val >= l2->val) {
				p->next = l2;
				l2 = l2->next;
			}
			else {
				p->next = l1;
				l1 = l1->next;
			}
			p = p->next;
		}

		p->next = l1 ? l1 : l2;
		return dummy.next;
	}
};