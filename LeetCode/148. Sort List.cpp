#include"x.h"

class Solution_148 {
public:
	ListNode * sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)return head;

		ListNode*fast = head;
		ListNode*slow = head;

		while (fast->next&&fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		//ListNode*leftend = slow;
		ListNode*l2begin = slow->next;
		slow->next = nullptr;

		ListNode*l1 = sortList(head);
		ListNode*l2 = sortList(l2begin);

		return mergeTwoList(l1, l2);
	}
	ListNode*mergeTwoList(ListNode*l1, ListNode*l2) {
		ListNode dummy(-1);
		ListNode*p = &dummy;
		while (l1&&l2) {
			if (l1->val >= l2->val) {
				p->next = l2;
				l2 = l2->next;
			}else {
				p->next = l1;
				l1 = l1->next;
			}
			p = p->next;
		}

		p->next = l1 ? l1 : l2;
		return dummy.next;
	}
};