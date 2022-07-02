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
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curptr = head;
        ListNode* leftptr = nullptr;
        ListNode* rightptr = nullptr;
        ListNode* startptr = nullptr;
        ListNode* subend = nullptr; // end of the prev sublist
        ListNode* alphaptr = nullptr;
        stack<int> bin;
        stack<int> bin2;
        if (k == 1) return head;
        // corner case: 1 node OR k=n
        // throw to bin until counter
        int cnt = 0;
        
        while (curptr != nullptr) {
            cnt++;
            bin.push(curptr->val);
            if (cnt == k) {
                while (!bin.empty()) {
                    // create new node with val from top of bin
                    int curval = bin.top(); bin.pop();
                    ListNode* nd = new ListNode(curval);
                    if (alphaptr == nullptr) alphaptr = nd; // first node of returned list
                    // link the previously created node
                    if (startptr == nullptr) { // record first node pos
                        startptr = nd;
                    } else {
                        leftptr->next = nd;
                    }
                    leftptr = nd;
                }
                // link prev part
                if (subend != nullptr) {
                    subend->next = startptr;  // previous end subend link to current sublist start position startptr
                } 
                subend = leftptr;         // subend update to current sublist end
                cnt = 0;
                startptr = nullptr;
                leftptr = nullptr;
            }
            curptr = curptr->next;
        }
        // restore rest if remained part is not enough
        if (cnt != k) {
            //if counter not reach but nullptr found, throw to another bin and restore
            cout << "bin2 content: " ;
            while (!bin.empty()) {
                int curval = bin.top();
                bin.pop();
                bin2.push(curval);
                cout << curval << " ";
            }
            leftptr = nullptr;
            while (!bin2.empty()) {
                // create new node with val from top of bin2
                int curval = bin2.top(); bin2.pop();
                ListNode* nd = new ListNode(curval);
                // link the previously created node
                if (startptr == nullptr) { // record first node pos
                    startptr = nd;
                } else {
                    leftptr->next = nd;
                }
                leftptr = nd;
            }
            // link to prev sublist 
            subend->next = startptr;  // previous end subend link to current sublist start position startptr
        }
        return alphaptr;
    }
};
