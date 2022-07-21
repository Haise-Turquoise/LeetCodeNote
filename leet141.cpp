/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curptr = head;
        unordered_map<ListNode*, int> m;
        while (curptr != nullptr) {
            if (m.find(curptr) == m.end() ) {  // not found
                m.insert({curptr,0});
            } else {
                return true;
            }
            curptr = curptr->next;
        }
        return false;
    }
};
