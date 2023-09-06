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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n=0;
        vector<ListNode*>arr;
        while(temp){   
            arr.push_back(temp);
            temp = temp->next;
            n++;
        }
        vector<ListNode*>ans;
        if(n<=k){
            int i=0;
            temp=head;
            while(i<k){
                if(temp){
                    ans.push_back(temp);
                    temp = temp->next;
                    ans.back()->next =NULL;

                }
                else ans.push_back(NULL);
                i++;
            }
            return ans;
        }
        int si = n/k;
        int rem = n%k;
        int i=0;
        while(i<n){
            ans.push_back(arr[i]);
            if(rem>0){
                i+=si+1;
                arr[i-1]->next =NULL;
                rem--;
            }
            else i+=si, arr[i-1]->next=NULL;
        }
        return ans;
    }
};
