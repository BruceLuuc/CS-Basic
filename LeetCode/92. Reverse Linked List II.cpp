#include"x.h"


class Solution {
public:
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		//要求1<=m<=n
		//在head头部添加一个dummy节点，把dummy挂到head头部
		ListNode dummy(-1);
		dummy.next = head;

		ListNode *prev = &dummy;
		for (int i = 1; i < m ; ++i)
			prev = prev->next;
		ListNode* const head2 = prev;


		prev = head2->next;
		ListNode *cur = prev->next;

		for (int i = m; i < n; ++i) {
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur; 
			cur = prev->next;
		}
		return dummy.next;
	}
};