#include"x.h"

class Solution_143_1 {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)return;

		ListNode*slow = head, *fast = head, *prev = nullptr;
		while (fast&&fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;//cut at middle
		slow=reverse_3(slow);
		//merge
		ListNode*curr = head;
		while (curr->next) {
			ListNode*tmp = curr->next;
			curr->next = slow;
			slow = slow->next;
			curr->next->next = tmp;
			curr = tmp;
		}
		curr->next = slow;
	}

	//复习一下链表反转
	ListNode*reverse_1(ListNode*head) {
		if (head == nullptr || head->next == nullptr)return head;
		ListNode*prev = head;
		for (ListNode*curr = prev->next, *next = curr->next; 
			curr; 
			prev = curr, curr = next, next = next ? next->next : nullptr) {
			curr->next = prev;
		}

		head->next = nullptr;
		return prev;	
	}
	ListNode*reverse_2(ListNode*head) {
		if (head == nullptr || head->next == nullptr)return head;
		ListNode*prev = head;
		ListNode*pcur = prev->next;

		while (pcur) {
			ListNode*pnext = pcur->next;
			pcur->next = prev;
			prev = pcur;
			pcur = pnext;
		}
		head->next = nullptr;
		return prev;
	}
	ListNode* reverse_3(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *p = reverse_3(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;

	}
};

int main_143() {
	auto g = new ListNode(7);
	auto f = new ListNode(6, g);
	auto e = new ListNode(5, f);
	auto d = new ListNode(4, e);
	auto c = new ListNode(3, d);
	auto b = new ListNode(2, c);
	auto a = new ListNode(1, b);
	__print_Link_Node(a);
	Solution_143_1 A;
	A.reorderList(a);
	__print_Link_Node(a);



	system("pause");
	return 0;
}