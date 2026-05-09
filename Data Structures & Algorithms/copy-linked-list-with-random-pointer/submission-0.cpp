/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        unordered_map<Node* ,Node* > convers;
        convers[nullptr]=nullptr;
        
        Node* currList2=new Node(head->val);
        Node* newList=currList2;
        convers[head]=newList;
        Node* curr=head->next;
        while(curr){
            newList->next=new Node(curr->val);
            convers[curr]=newList->next;
            curr=curr->next;
            newList=newList->next;
        }
        curr=head;
        newList=currList2;
        while(curr){
            newList->random=convers[curr->random];
            curr=curr->next;
            newList=newList->next;
        }
        return currList2;
    }
};
