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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        // Move prev to node before 'left'
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        ListNode* nextnode=nullptr;
        ListNode* reverseprev=nullptr;
        for(int i=0;i<right-left+1;i++){
            nextnode=curr->next;
            curr->next=reverseprev;
            reverseprev=curr;
            curr=nextnode;
        }
        prev->next->next=curr;
        prev->next=reverseprev;
        return dummy->next;
    }
};