class PrefixTree {
    struct Node{
        Node* node[26]={};
        bool isEnd;
    };
    Node* root;
public:
    PrefixTree() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        
        for(char c: word){
            int i=c-'a';
            if(!curr->node[i]){
                curr->node[i]=new Node();
            }
            curr=curr->node[i];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node *curr=root;
        for(char c:word){
            int i=c-'a';
            if(!curr->node[i])
                return false;
            curr=curr->node[i];
        }
        if(curr->isEnd)
            return true;
        return false;

    }
    
    bool startsWith(string prefix) {
        Node * curr =root;
        for(char c:prefix){
            int i=c-'a';
            if(!curr->node[i])
                return false;
            curr=curr->node[i];
        }
        return true;
    }
};
