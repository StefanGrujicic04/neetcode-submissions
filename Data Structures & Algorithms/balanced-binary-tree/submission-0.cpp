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
    bool isBalanced(TreeNode* root) {

        return checkingHeight(root)!=-1;
        
    }
    int checkingHeight(TreeNode* root){
        if (!root)
            return true;
        int left= checkingHeight(root->left);
        if(left==-1)return -1;

        int right= checkingHeight(root->right);
        if(right==-1)return -1;

        if(abs(left-right)>1)
            return -1;
        else 
            return max(left,right)+1;        
    }
};
