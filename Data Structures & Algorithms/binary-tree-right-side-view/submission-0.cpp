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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>results;
        queue<TreeNode*> levels;
        if(!root)
            return results;
        levels.push(root);
        while(!levels.empty()){
            int size=levels.size();
            
            TreeNode*node=levels.front();
            levels.pop();
            size--;
            results.push_back(node->val);
            if(node->right)
                levels.push(node->right);
            if(node->left)
                levels.push(node->left);
            
            for(int i=0;i<size;i++){
                node=levels.front();
                levels.pop();
                if(node->right)
                    levels.push(node->right);
                if(node->left)
                    levels.push(node->left);
            }
        }
        return results;
    }
};
