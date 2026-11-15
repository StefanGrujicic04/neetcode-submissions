/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast= head, *slow=head;
        if(head==nullptr)
            return ;
        
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==slow)
            return ;
        
        ListNode* prev=nullptr;
        ListNode* tmp=slow->next;
        slow->next=nullptr;
        while(tmp!=nullptr){
            ListNode* cur=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=cur;
        }
        ListNode*curr=head;
        while(curr!=nullptr&&fast!=nullptr)
        {   
            ListNode* tmp= curr->next;
            curr->next=fast;
            fast=fast->next;
            curr->next->next=tmp;
            curr=tmp;
        }
        
    }
};
