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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        if(head==nullptr)
            return false;
        while(head->next!=nullptr){
            if(seen.count(head))
                return true;
            seen.insert(head);
            head=head->next;
        }
        return false;
    }
};
