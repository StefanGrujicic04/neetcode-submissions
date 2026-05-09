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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)
            return list2;
        if(list2==nullptr)
            return list1;
        if(list1->val>list2->val)
            swap(list1,list2);
        ListNode* head=list1;
        while(head->next!=nullptr&&list2!=nullptr){
            if(head->val<=list2->val&&head->next->val>=list2->val){
                ListNode* curr=list2;
                list2=list2->next;
                ListNode*next=head->next;

                head->next=curr;
                curr->next=next;  
            }
            head=head->next;

        }
        if(list2!=nullptr){
            head->next=list2;
        }
        return list1;
    }
};
