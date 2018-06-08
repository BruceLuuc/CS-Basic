#include"x.h"

//效率低下,beats 2.99%
class Solution_61_1 {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode *tmp,*p;
		int len=1,m;
		for (p = head; p->next != nullptr; p = p->next, ++len);
		m = k % len;

		for (int i = 0; i != m; ++i) {	
			for (tmp = head; tmp->next->next != nullptr; tmp = tmp->next);
			tmp->next->next = head;
			head = tmp->next;
			tmp->next = nullptr;
		}
		return head;
	}	
};


//优化
class Solution_61_2 {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0) return head;

		int len = 1;
		ListNode *p = head;		
		for (; p->next != nullptr; p = p->next, ++len);
		k = len - k % len;
		p->next = head;//把链表接成环
		for (int i = 0; i != k; ++i, p = p->next);//继续前几k步
		head = p->next;
		p->next = nullptr;//断开环
		return head;
	}
};

//稍改，大同小异
class Solution_61_3 {
public:
	ListNode * rotateRight(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0) return head;

		int len = 1;
		ListNode* p = head;
		while (p->next) { 
			len++;
			p = p->next;
		}
		k= len-k % len;
		p->next = head; 
		for (int step = 0; step < k; step++) {
			p = p->next; 
		}
		head = p->next; 
		p->next = nullptr; 
		return head;
	}
};

