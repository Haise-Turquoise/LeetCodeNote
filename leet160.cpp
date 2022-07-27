/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) return nullptr;
        unordered_map<ListNode*, int> hm;
        ListNode* curptr = headA;
        while (curptr != nullptr) {
            hm.insert(make_pair(curptr, 0) );
            curptr = curptr->next;
        }
        curptr = headB;
        while (curptr != nullptr) {
            if (hm.find(curptr) != hm.end() ) { //found means != hm.end()
                //cout << curptr->next->val << endl;
                return curptr;
            }
            curptr = curptr->next;
        }
        return nullptr;
    }
};
