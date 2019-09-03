#include"x.h"



class Solution_83_1 {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		//�սڵ��ֻ��һ���ڵ㣬ֱ�ӷ���
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

//�ݹ�
class Solution_83_2 {
public:
	ListNode * deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr)return head;

		ListNode dummy(head->val + 1); // ����headһ������
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