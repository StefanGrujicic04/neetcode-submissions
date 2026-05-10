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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(p->val>q->val)
            swap(p,q);
        TreeNode *curr=root;
        while(curr){
            if(curr->val >= p->val&&curr->val<=q->val)
                return curr;
            else if(curr->val < p->val)
                curr=curr->right;
            else
                curr=curr->left;
        }
        return curr;
        
    }
};
