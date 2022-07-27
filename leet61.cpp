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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if (head == nullptr) return head;
        
        ListNode* curptr = head;
        ListNode* bptr = nullptr;
        int cnt = 0;
        while (curptr!= nullptr) {
            cnt ++;
            bptr = curptr;
            curptr = curptr->next;
        }
        int size = cnt;
        int k0 = k%size;
        if (k0 == 0) return head;
        // 3 = 5-2 = size - k store 4, cut 3, link 5 to 3
        int pos = size - k0;
        curptr = head;
        for (int i = 1; i < pos; i++) {
            curptr = curptr->next;
        }
        ListNode* newhead = curptr->next;
        curptr->next = nullptr;
        bptr->next = head;
        return newhead;
    }
};
