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
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* thisa = l1;
        ListNode* thisb = l2;
        ListNode* leftptr = nullptr;
        ListNode* startptr = nullptr;
        while (thisa != nullptr || thisb != nullptr) {  // 注意用OR BOTH NOT来保证双结束才停止
            int a = 0, b = 0;
            if (thisa != nullptr) a = thisa->val;
            if (thisb != nullptr) b = thisb->val;
            ListNode* nd = new ListNode(a + b);
            if (leftptr != nullptr) {
                leftptr->next = nd;   //记录左侧位置后从左往右连
            }
            else {
                startptr = nd;   //注意记录起始位置
            }
            leftptr = nd;
            if (thisa != nullptr) thisa = thisa->next;  //注意->需要确认非nullptr
            if (thisb != nullptr) thisb = thisb->next;
        }
        ListNode* thisc = startptr;
        int overflow = 0; //进位
        ListNode* thisptr = thisc;
        /*cout << "before process";
        while (thisptr != nullptr) {
            cout << thisptr->val << ",";
            thisptr = thisptr->next;
        }
        cout << endl;*/
        ListNode* lastptr = nullptr;
        while (thisc != nullptr) {
            int tmp = thisc->val + overflow;  //先求和再进位！
            thisc->val = tmp % 10;
            overflow = tmp / 10;
            lastptr = thisc; // 记录左侧ptr保证总数多进一位，也就是list长度+1
            thisc = thisc->next;
        }
        if (overflow != 0) {
            ListNode* ovd = new ListNode(overflow);
            lastptr->next = ovd;
        }
        return startptr;
        
        
        // try to transfer node list to INT type by stack operation, worked for int range but not work for out of range version
        /*
        ListNode* thisa = l1;
        ListNode* thisb = l2;
        ListNode* leftptr = nullptr, startptr = nullptr;
        while ( thisa!=nullptr && thisb!=nullptr ) {
            ListNode* nd = new ListNode(thisa->val+thisb->val);
            if (leftptr != nullptr) {
                leftptr->next = nd;
            } else {
                startptr = nd;
            }
            leftptr = nd;
            thisa = thisa->next;
            thisb = thisb->next;
        }
        return startptr;
        
        int a = 0;
        int b = 0;
        if (l1->val == 0) a = 0;
        if (l2->val == 0) b = 0;
        stack<int> sa;
        stack<int> sb;
        ListNode* thisa = l1;
        ListNode* thisb = l2;
        int expa = -1;
        while (thisa != nullptr) {
            expa++;
            sa.push(thisa->val);
            thisa = thisa->next;
        }
        while (!sa.empty()) {
            int x = sa.top();
            sa.pop();
            a += x * pow(10, expa);
            expa--;
        }
        int expb = -1;
        while (thisb != nullptr) {
            expb++;
            sb.push(thisb->val);
            thisb = thisb->next;
        }
        while (!sb.empty()) {
            int x = sb.top();
            sb.pop();
            b += x * pow(10, expb);
            expb--;
        }
        int c = a + b;

        int n = c, reversed_number = 0, remainder;

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
        /*
        while (n != 0) {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        c = reversed_number;
        cout << "reversed c: " << c << endl;
        
        ListNode* leftptr = nullptr;
        ListNode* startptr = nullptr;
        bool singDigit = false;
        if (c < 10) singDigit = true;
        while (c >= 10) {
            ListNode* nd = new ListNode();
            if (leftptr != nullptr) {
                leftptr->next = nd;
            }
            else {
                startptr = nd;
            }
            nd->val = c % 10;
            leftptr = nd;
            c = c / 10;
        }
        ListNode* ld = new ListNode();
        ld->val = c;
        ld->next = nullptr;
        if (leftptr != nullptr) leftptr->next = ld;
        if (singDigit) startptr = ld;
        return startptr;
        */
    }
};
    }
};
