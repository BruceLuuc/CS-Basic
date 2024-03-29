﻿#include"x.h"

class Solution_22_1 {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)return l2;
		if (l2 == nullptr)return l1;

		ListNode dummy(-1);
		ListNode *p = &dummy;

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
		//指向剩余的部分
		p->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

class Solution_21_2 {
public:
	ListNode * mergeTwoLists(ListNode*l1, ListNode*l2) {
		if (l1 == nullptr)return l2;
		if (l2 == nullptr)return l1;
		ListNode*head = l1->val < l2->val?l1:l2;
		ListNode*__next= l1->val < l2->val ? l2 : l1;

		head->next = mergeTwoLists(head->next, __next);

		return head;
	}
};