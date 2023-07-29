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
    int widthOfBinaryTree(TreeNode* root) {
        //used unsinged long long int for avoiding OVERFLOW issues 
        unsigned long long int ans = 0;
        if(root==NULL)
        return ans;
        queue<pair<TreeNode*,unsigned long long int >>q;
        q.push({root,0});
        while(!q.empty()){
            int n =q.size();
            unsigned long long int left = q.front().second,right = q.back().second;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                unsigned long long int  par = q.front().second;
                q.pop();
                if(node->left) q.push({node->left,2*par + 1});
                if(node->right) q.push({node->right,2*par +2});
            }
            ans = max(ans,right-left+1);
        }
        return ans;

    }
};