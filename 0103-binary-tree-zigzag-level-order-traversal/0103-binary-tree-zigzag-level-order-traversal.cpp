/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            for(int i =0;i<n;i++){
                TreeNode* tn = q.front();
                q.pop();
                temp.push_back(tn->val);
                if(tn->left)
                q.push(tn->left);
                if(tn->right)
                q.push(tn->right);
            }
            if(level&1)
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            level++;
        }
        return ans;

    }
};