#include<iostream>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
            if(root==nullptr) return nullptr;
            auto left=increasingBST(root->left);
            auto right=increasingBST(root->right);
            root->right=left;
            root->left=nullptr;
            if(right==nullptr) return root;
            auto npr=right;
            while(npr->right!=nullptr) npr=npr->right;
            npr->right=root;
            return right;
    }
};