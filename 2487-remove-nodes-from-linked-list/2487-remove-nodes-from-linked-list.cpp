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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = head->next;
        while(nex){
            curr->next = prev;
            prev = curr;
            curr=nex;
            nex = nex->next;
        }
        curr->next = prev;
        int mi=curr->val;
        //return curr;
        ListNode* temp = curr;
        while(temp && temp->next){
            // cout<<temp->val<<endl;
            if(temp->next->val<mi){
                temp->next =temp->next->next;
            }
            else{
                mi = temp->next->val;
                temp = temp->next;
            }
        }
        // if(temp && temp->next){
        //     if(temp->next->val<mi)
        //     temp->next= NULL;
        // }
        if(curr==NULL || curr->next==NULL)
        return curr;
        prev = NULL;
        nex = curr->next;
        while(nex){
            curr->next = prev;
            prev = curr;
            curr=nex;
            nex = nex->next;
        }
        curr->next = prev;
        return curr;
    }
};