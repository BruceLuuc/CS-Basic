#include"x.h"



class Solution_83_1 {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		//空节点或只有一个节点，直接返回
		if (head == nullptr||head->next==nullptr)return head;

		for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
			if (prev->val == cur->val) {
				prev->next = cur->next;
				delete cur;
			}
			else {
				prev = cur;
			}
		}
		return head;

	}
};

//递归
class Solution_83_2 {
public:
	ListNode * deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr)return head;

		ListNode dummy(head->val + 1); // 不跟head一样即可
		dummy.next = head;
		recur(&dummy, head);
		return dummy.next;
	}
private:
	static void recur(ListNode *prev, ListNode *cur) {
		if (cur == nullptr) return;
		if (prev->val == cur->val) {
			prev->next = cur->next;
			delete cur;
			recur(prev, prev->next);
		}
		else {
			recur(prev->next, cur->next);
		}
	}
};