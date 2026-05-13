class WordDictionary {
    struct Node{
        Node* nodes[26]={};
        unsigned int prefix=0;
        bool isEnd=false;
    };
    Node* root;
public:
    WordDictionary() {
        root=new Node();

    }
    
    void addWord(string word) {
        Node* curr=root;
        for(char c: word){
            int i=c-'a';
            if(!curr->nodes[i])
            {
                curr->nodes[i]=new Node();
            }        
            curr->prefix++;
            curr=curr->nodes[i];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        if(word.empty())
            return false;
        return recSearch(word,0,root);
    }
    bool recSearch(const string & word, int position, Node* curr){
        if(!curr) return false;
        if(position==word.size())return curr->isEnd;

        if(word[position]=='.'){
            bool found=false;
            for(int i=0; i<26 && !found ;i++){
                if(!curr->nodes[i])
                    continue;
                found=found|| recSearch(word,position+1,curr->nodes[i]);
            }
            return found;
        }
        else{
            int i=word[position]-'a';
            return recSearch(word,position+1,curr->nodes[i]);
        }
        
    }
};
