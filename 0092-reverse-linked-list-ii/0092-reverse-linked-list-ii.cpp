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
        if(head==NULL || head->next==NULL || left==right)
        return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        for(int i=0;i<left-1;i++){
            prev = curr;
            curr=curr->next;
        }
        ListNode* nxt = curr->next;
        ListNode* stpos = prev;
        ListNode* stpos1 = curr;
        for(int i=0;i<right-left && nxt;i++){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        stpos->next = curr;
        stpos1->next=nxt;
        return dummy->next;

    }
};