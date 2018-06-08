#include"x.h"

class Solution_82_1 {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == nullptr||head->next==nullptr) return head;

		ListNode dummy(INT_MIN); 
		dummy.next = head;
		ListNode *prev = &dummy, *cur = head;

		while (cur != nullptr) {
			bool duplicated = false;
			while (cur->next != nullptr && cur->val == cur->next->val) {
				duplicated = true;
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
			}
			if (duplicated) { 
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
				continue;
			}
			prev->next = cur;
			prev = prev->next;
			cur = cur->next;
		}
		prev->next = cur;
		return dummy.next;
	}
};

//µİ¹é
class Solution_82_2 {
public:
	ListNode * deleteDuplicates(ListNode *head) {
		if (!head || !head->next) return head;

		ListNode *p = head->next;
		if (head->val == p->val) {
			while (p && head->val == p->val) {
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			delete head;
			return deleteDuplicates(p);
		}
		else {
			head->next = deleteDuplicates(head->next);
			return head;
		}
	}
};