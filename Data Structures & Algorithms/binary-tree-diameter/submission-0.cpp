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
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeRecursive(root).first;
    }
    pair<int,int> diameterOfBinaryTreeRecursive(TreeNode* node){
        if(!node)
            return make_pair(-1,-1);
        pair<int,int> leftpath=diameterOfBinaryTreeRecursive(node->left);
        pair<int,int> rightpath=diameterOfBinaryTreeRecursive(node->right);
        int second=1+max(rightpath.second,leftpath.second);
        int first=rightpath.second+leftpath.second+2;
        first=max(max(first,leftpath.first),rightpath.first);
        return make_pair(first,second);
    
    }
};
