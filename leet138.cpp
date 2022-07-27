/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*,Node*> oc;
        
        Node* curptr = head;
        Node* prevptr = nullptr;
        Node* nd = nullptr;
        Node* newhead = nullptr;
        while (curptr != nullptr) {
            nd = new Node(curptr->val);
            
            oc.insert(make_pair(curptr, nd)); // record the mirror relationship
            
            if (prevptr == nullptr) {     // if first copy node, memorize new head
                newhead = nd;
            } else {
                prevptr->next = nd;      // if not first, link prev and cur copy node
            }
            
            prevptr = nd;
            curptr = curptr->next;
        }
        
        // link random attribute of copy list
        curptr = head;
        while (curptr != nullptr) {
            if (curptr->random == nullptr) {
                oc[curptr]->random = nullptr;
            } else {
                oc[curptr]->random = oc[curptr->random];
            }
            curptr = curptr->next;
        }
        return newhead;
    }
};
