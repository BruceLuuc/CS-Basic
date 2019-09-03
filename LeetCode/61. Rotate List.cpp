#include"x.h"

//Ч�ʵ���,beats 2.99%
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


//�Ż�
class Solution_61_2 {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0) return head;

		int len = 1;
		ListNode *p = head;		
		for (; p->next != nullptr; p = p->next, ++len);
		k = len - k % len;
		p->next = head;//������ӳɻ�
		for (int i = 0; i != k; ++i, p = p->next);//����ǰ��k��
		head = p->next;
		p->next = nullptr;//�Ͽ���
		return head;
	}
};

//�Ըģ���ͬС��
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

