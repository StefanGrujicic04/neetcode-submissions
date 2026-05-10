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
        int level;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<Frame>levelQueue;
        vector<vector<int>>result;
        levelQueue.push({root,0});
        while(!levelQueue.empty()){
            
            Frame curr=levelQueue.front();
            levelQueue.pop();

            if(!curr.node)
                continue;
            if(curr.level>=result.size())
                result.push_back({});
            result[curr.level].push_back(curr.node->val);
            levelQueue.push({curr.node->left,curr.level+1});
            levelQueue.push({curr.node->right,curr.level+1});
        }
        return result;
    }
};
