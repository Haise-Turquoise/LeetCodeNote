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

#include <stack>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curptr = head;
        ListNode* leftptr = nullptr;
        ListNode* rightptr = nullptr;
        ListNode* startptr = nullptr;
        stack<int> bin;
        stack<int> bin2;
        if (k == 1) return head;
        // corner case: 1 node OR k=n
        // throw to bin until counter
        int cnt = 0;
        
        while (curptr != nullptr) {
            if (cnt == k) break;
            cnt++;
            bin.push(curptr->val);
            curptr = curptr->next;
        }
        
        
        
        
        
        // create reverse sublist and link to previous 
        if (cnt == k) {
            // curptr is on the start of the next sublist
            
            while (!bin.empty()) {
                // create new node with val from top of bin
                int curval = bin.top();
                bin.pop();
                ListNode* nd = ListNode(curval);
                // link the previously created node
                if (startptr == nullptr) {
                    startptr = nd;
                } else {
                    leftptr->next = nd;
                }
                leftptr = nd;
            }
            // link prev part
            if (subend != nullptr) {
                subend->next = startptr;  // previous end subend link to current sublist start position startptr
                subend = leftptr;         // subend update to current sublist end
            }
        } else {//if counter not reach but nullptr found, throw to another bin and restore
            while (!bin.empty()) {
                int curval = bin.top();
                bin.pop();
                bin2.push(curval);
            }
            leftptr = nullptr;
            while (!bin2.empty()) {
                // create new node with val from top of bin2
                int curval = bin2.top();
                bin2.pop();
                ListNode* nd = ListNode(curval);
                // link the previously created node
                if (leftptr != nullptr) {
                    leftptr->next = nd;
                }
                leftptr = nd;
            }
            // link to prev sublist 
            subend->next = startptr;  // previous end subend link to current sublist start position startptr
        }
        cnt == 0;
        
            
        
        
        
        
        
        
        
        
    }
};
