#include"x.h"

class Solution_141_1 {
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};


//ÀûÓÃsetÈİÆ÷
class Solution_141_2 {
public:
	bool hasCycle(ListNode *head) {
		set<ListNode*>set_node;
		for (ListNode *p = head; p; p = p->next) {
			if (set_node.find(p)!=set_node.end())return true;
			else set_node.insert(p);
		}
		return false;
	}
};