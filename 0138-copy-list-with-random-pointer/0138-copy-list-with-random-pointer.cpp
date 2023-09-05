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
        if(head==NULL)
            return NULL;
        Node* dummy = new Node(0);
        Node*  temp = head;
        Node*  temp1 = dummy;
        unordered_map<Node*, Node*>mp;
        while(temp){
            temp1->next = new Node(temp->val);
            if(temp->random ==NULL){
                temp1->next->random = NULL;
            }
            mp[temp] = temp1->next;
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp = head;
        temp1 = dummy;
        temp1 = temp1->next;
        while(temp){
            if(temp->random !=NULL){
                temp1->random = mp[temp->random];
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        return dummy->next;


    }
};