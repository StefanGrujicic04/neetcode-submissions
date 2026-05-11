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
    struct Frame{
        TreeNode* node;
        bool been;

    };
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<Frame> dfs;
        if(!root)
            return -1;
        dfs.push({root,false});
        int curr_k=0;
        while(!dfs.empty()){
            Frame curr=dfs.top();
            dfs.pop();
            if(curr.been|| (! curr.node->left && ! curr.node->right ) )
                curr_k++;
            if(!curr.been&& ( curr.node->left || curr.node->right ) ){
                if(curr.node->right) dfs.push({curr.node->right,false});
                dfs.push({curr.node,true});
                if(curr.node->left) dfs.push({curr.node->left,false});
            }
            if(curr_k==k)
                return curr.node->val;
        }
        
        return curr_k;
    }
};
