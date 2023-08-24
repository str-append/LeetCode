/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* prev = node;
        while(temp->next){
            swap(temp->val,temp->next->val);
            prev = temp;
            temp=temp->next;
        }
        prev->next=nullptr;
    }
};