#include"x.h"



class Solution_86_1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;
        for (ListNode *cur = head; cur;cur=cur->next){
            if(cur->val<x){
                left_cur->next = cur;
                left_cur = cur;
            }else{
                right_cur->next = cur;
                right_cur = cur;
            }
        }

        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        return left_dummy.next;
    }
};