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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(root->val);
            return ret;
        }
        vector<int> l,r;
        if (root->left != nullptr) {
            l = postorderTraversal(root->left);
            ret.insert(ret.end(), l.begin(), l.end() );
        }
        
        if (root->right != nullptr) {
            r = postorderTraversal(root->right);
            ret.insert(ret.end(), r.begin(), r.end() );
        }
        ret.push_back(root->val);
        return ret;
    }
};
