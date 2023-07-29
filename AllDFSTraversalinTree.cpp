#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void dfs(BinaryTreeNode<int>*root,vector<int>&ino,vector<int>&po,vector<int>&pr){
    if(root==NULL)
    return;
    pr.push_back(root->data);
    dfs(root->left,ino,po,pr);
    ino.push_back(root->data);
    dfs(root->right,ino,po,pr);
    po.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int>ino;
    vector<int>po;
    vector<int>pr;
    vector<vector<int>>ans;
    dfs(root,ino,po,pr);
    ans.push_back(ino);
    ans.push_back(pr);
    ans.push_back(po);
    return ans;
}
