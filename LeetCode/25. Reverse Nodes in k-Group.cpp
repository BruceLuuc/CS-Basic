#include"x.h"


//难度比较大，回头再看
class Solution_25_1 {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;

		for (ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // 不足 k 个
			prev = reverse(prev, prev->next, end);
		}
		return dummy.next;
	}
	// prev 是 first 前一个元素, [begin, end] 闭区间，保证三者都不为 null
	// 返回反转后的倒数第一个元素
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		for (ListNode *p = begin, *cur = p->next, *next = cur->next;
			cur != end_next;
			p = cur, cur = next, next = next ? next->next : nullptr) {
			cur->next = p;
		}
		begin->next = end_next;
		prev->next = end;
		return begin;
	}
};