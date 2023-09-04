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
    unordered_map<int,int>mp;
    int subtreesum(TreeNode* root){
        if(root==NULL)
        return 0;
        int sum = subtreesum(root->left)+subtreesum(root->right)+root->val;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int a = subtreesum(root);
        vector<int>ans;
        int msum=0;
        for(auto &i:mp)
        if(msum<i.second)
        msum=i.second;
        for(auto &i:mp)
        if(i.second==msum)
        ans.push_back(i.first);
        return ans; 
    }
};