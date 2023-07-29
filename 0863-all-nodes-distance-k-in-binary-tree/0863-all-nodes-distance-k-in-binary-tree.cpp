/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void creategraph(TreeNode* root, unordered_map<int,vector<int>>&graph){
        if(root==NULL)
        return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        creategraph(root->left,graph);
        creategraph(root->right,graph);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        unordered_map<int,vector<int>>graph;
        creategraph(root,graph);
        queue<pair<int,int>>q;
        unordered_set<int>vis;
        q.push({target->val,0});
        vis.insert(target->val);
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist==k)
            ans.push_back(node);
            for(auto i:graph[node]){
                if(vis.find(i)==vis.end()){
                    q.push({i,dist+1});
                    vis.insert(i);
                }
            }
        }
        return ans;


    }
};