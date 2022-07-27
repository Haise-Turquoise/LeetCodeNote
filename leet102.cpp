/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        
        
        vector<TreeNode*> curlvlptr, nxtlvlptr;
        curlvlptr.emplace_back(root);
        
        vector<int> tmp;
        tmp.push_back(root->val);
        ret.push_back(tmp);
        
        vector<int> level;
        while (curlvlptr.size()!= 0) {
            for (auto curptr : curlvlptr) {
                if (curptr->left != nullptr) {
                    nxtlvlptr.emplace_back(curptr->left);
                    level.emplace_back(curptr->left->val);
                }
                if (curptr->right != nullptr) {
                    nxtlvlptr.emplace_back(curptr->right);
                    level.emplace_back(curptr->right->val);
                }
            }
            /*
            curlvlptr = nxtlvlptr;
            for (auto pr: curlvlptr) {
                cout << pr->val << endl;
            }
            
            curlvlptr.clear();
            for (auto pr: nxtlvlptr) {
                curlvlptr.push_back(pr);
            }
            nxtlvlptr.clear();
            */
            curlvlptr = nxtlvlptr;
            nxtlvlptr.clear();
            if (level.size()!=0) {
                ret.push_back(level);
            } else {
                return ret;
            }
            level.clear();
        }
        return ret;
        
    }
};
