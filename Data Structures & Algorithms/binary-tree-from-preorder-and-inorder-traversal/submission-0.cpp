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
    unordered_map<int,int> idx;
    int preIdx=0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            idx[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd ){
        if(preStart>preEnd)
            return nullptr;
        int nodeVal=preorder[preIdx++];
        TreeNode* node= new TreeNode(nodeVal);
        int mid= idx[nodeVal];
        node->left=build(preorder,preStart,mid-1);
        node->right=build(preorder,mid+1,preEnd);
        return node;
    }
};
