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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* prev=nullptr;
        int carry=0;
        while(curr1&&curr2){
            curr1->val+=curr2->val+carry;
            carry=curr1->val/10;
            curr1->val%=10;
            prev=curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(!curr1){
            prev->next=curr2;
        }
        while(prev->next){
            prev=prev->next;
            prev->val+=carry;
            carry=prev->val/10;
            prev->val%=10;
        }
        if(carry){
            prev->next=new ListNode(1);
        }
        return l1;

    }
};
