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

class Codec {
    void serialize(TreeNode* root,ostringstream& ss){
        if(!root){ss<<"N,"; return;}
        ss<<root->val<<",";
        serialize(root->left,ss);
        serialize(root->right,ss);
    }
    TreeNode* deserialize(istringstream& ss){
        string tok;
        if( !getline(ss,tok,',')||tok=="N" ){
            return nullptr;
        }
        TreeNode* newNode=new TreeNode(stoi(tok));
        newNode->left=deserialize(ss);
        newNode->right=deserialize(ss);
        return newNode;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize(ss);
    }
};
