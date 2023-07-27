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
    void traversal(TreeNode* node,map<int,vector<pair<int,int>>>&map,int level,int depth){
        if(node==NULL)
        return ;
        map[level].push_back({depth,node->val});
        if(node->left)
        traversal(node->left,map,level-1,depth+1);
        if(node->right)
        traversal(node->right,map,level+1,depth+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>map;
        vector<vector<int>>ans;
        traversal(root,map,0,0);
        for(auto i:map){
            vector<int>temp;
            sort(i.second.begin(),i.second.end());
            for(auto j:i.second)
            temp.push_back(j.second);
            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;

    }
};