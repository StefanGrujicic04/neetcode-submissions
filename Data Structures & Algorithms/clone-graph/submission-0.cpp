/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> parallels;
        parallels[nullptr]=nullptr;
        create_dfs(node,parallels);
        connect_dfs(node,parallels);
        return parallels[node];
    }
    void create_dfs(Node* curr, unordered_map<Node*,Node*>& par){
        if(par.count(curr)) return;
        par[curr]=new Node(curr->val);
        for(Node* currChild:curr->neighbors){
            create_dfs(currChild,par);
        }
    }
    void connect_dfs(Node* curr, unordered_map<Node*,Node*>& par){
        if(!curr) return;
        if(!par[curr]->neighbors.empty())return;
        for(int i=curr->neighbors.size()-1;i>=0;i--){
            par[curr]->neighbors.push_back(par[curr->neighbors[i]]);
        }
        for(Node* currChild:curr->neighbors){
            connect_dfs(currChild,par);
        }
    }
};
