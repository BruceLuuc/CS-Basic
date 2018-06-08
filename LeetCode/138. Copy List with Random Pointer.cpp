#include"x.h"


 //Definition for singly-linked list with a random pointer.
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution_138_1 {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		//�½ڵ���뵽�ɽڵ����
		for (RandomListNode* cur = head; cur != nullptr; ) {
			RandomListNode* node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}

		//����randomָ��ָ��
		for (RandomListNode* cur = head; cur != nullptr; ) {
			if (cur->random != NULL)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		// �ֲ���������
		RandomListNode dummy(-1);
		for (RandomListNode* cur = head, *new_cur = &dummy;
			cur != nullptr; ) {
			//�ȸ���new_cur
			new_cur->next = cur->next;
			new_cur = new_cur->next;
			//�ٴ���ɽڵ�
			cur->next = new_cur->next;
			cur = cur->next;
		}
		return dummy.next;
	}
};