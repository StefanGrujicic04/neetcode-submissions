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
    struct Frame{
        TreeNode* node;
        int max1;
    };
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int goodNodes=1;
        queue<Frame>levels;
        levels.push({root->left,root->val});
        levels.push({root->right,root->val});
        while(!levels.empty()){
            Frame curr=levels.front();
            levels.pop();
            TreeNode* node=curr.node;
            if(!node)
                continue;
            int max1=curr.max1;  
            max1=max(max1,node->val);
            if(node->val>=curr.max1)  
                goodNodes++;
            levels.push({node->left,max1});
            levels.push({node->right,max1});
        }
        return goodNodes;
    }
};
