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
        int lesser;
        int greater;
    };
    bool isValidBST(TreeNode* root) {
        if(!root)
            return false;
        queue<Frame>levels;
        levels.push({root,INT_MAX,INT_MIN});
        while(!levels.empty()){
            Frame frame=levels.front();
            levels.pop();
            if(!frame.node)
                continue;
            if(frame.node->val<=frame.greater || frame.node->val>=frame.lesser)
                return false;
            levels.push({ frame.node->left, min(frame.node->val,frame.lesser), frame.greater });

            levels.push({frame.node->right, frame.lesser, max( frame.node->val, frame.greater)});
        }
        return true;
    }
};
