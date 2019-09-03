#include"x.h"


//递推
class Solution_206_1 {
public:
	ListNode * reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;

		ListNode *pCur, *pPre, *pNext;
		pPre = head;
		pCur = pPre->next;

		while (pCur) {
			pNext = pCur->next;
			pCur->next = pPre;

			pPre = pCur;
			pCur = pNext;
		}

		head->next = nullptr;
		head = pPre;

		return head;

	}
};

//递归
class Solution_206_2 {
public:
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
        
    }
};

//递推  改用for循环
class Solution_206_3 {
public:
	ListNode * reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *prev = head;
		for (ListNode *curr = head->next, *next = curr->next; curr;
			prev = curr, curr = next, next = next ? next->next : nullptr) {
			curr->next = prev;
		}
		head->next = nullptr;
		return prev;
	}
};