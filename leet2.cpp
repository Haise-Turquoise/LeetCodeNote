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
#include <cmath>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0; int b = 0;
        if ( l1->val == 0 ) a = 0;
        if ( l2->val == 0 ) b = 0;
        stack<int> sa;
        stack<int> sb;
        ListNode* thisa = l1; ListNode* thisb = l2;
        while ( thisa != nullptr ) {
            sa.push(thisa->val);
            thisa = thisa->next;
        }
        int expa = 0;
        while ( !sa.empty() ) {
            int x = sa.top();
            sa.pop();
            a += x * pow(10, expa);
            expa++;
        }
        while ( thisb != nullptr ) {
            sa.push(thisb->val);
            thisb = thisb->next;
        }
        int expb = 0;
        while ( !sb.empty() ) {
            int x = sb.top();
            sb.pop();
            b += x * pow(10, expb);
            expb++;
        }
        int c = a+b;
        int n = c, reversed_number = 0, remainder;
        while(n != 0) {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        c = reversed_number;
        ListNode * leftptr = nullptr;
        ListNode * startptr= nullptr;
        while (c > 10) {
            ListNode * nd = new ListNode();
            if (leftptr!=nullptr) {
                leftptr->next = nd;
            } else {
                startptr = nd;
            }
            nd->val = c%10;
            leftptr=nd;
            c = c/10;
        }
        ListNode * ld = new ListNode();
        ld->val = c;
        ld->next = nullptr;
        leftptr->next = ld;
        return startptr;
    }
};
