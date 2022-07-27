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

using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //vector<ListNode*> ndl;
        if (head==nullptr || head->next == nullptr) return head;
        ListNode* a = head, *b = head ,*c = nullptr;
        // a is left most of processed list, b is right most of processed list, c is 
        // left most of unprocessed list
        c = head->next;
        while (c!= nullptr) {
            ListNode* tmpc = c; //left most of unprocessed list need to be placed to leftmost of processed list
            c = c->next;       // update position of leftmost of unprocessed list
            
            tmpc->next = a;    // link new leftmost and old leftmost of processed list
            
            
            a = tmpc;         // update position of leftmost of processed list
            
        }
        b->next = nullptr;
        return a;
    }
};
