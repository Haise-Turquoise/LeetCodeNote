/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode * thisptr = head;
        while (thisptr != nullptr) {
            len++;
            thisptr = thisptr->next;
        }
        int cutpos = len-n, loc = 0;
        thisptr = head;
        ListNode* leftptr = nullptr;
        if (cutpos == 0) {   //注意处理删除首个，也就是cutpos为0，而不是n为0，因为n是倒着数的
            std:cout << "enter n == 1";
            ListNode* rightptr = thisptr->next;
            thisptr->next = nullptr;
            delete thisptr;
            return rightptr;
        }
        
            
        while ((thisptr != nullptr) && ( loc!=cutpos )) {
            loc++;
            leftptr = thisptr;
            thisptr = thisptr->next;
        }
        ListNode* rightptr = thisptr->next;
        thisptr->next = nullptr;
        delete thisptr;
        leftptr->next = rightptr;
        return head;
    }
};
