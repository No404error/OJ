#include<iostream>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(find_tree_depth(root)==-1) return false;
        else return true;
    }
    int find_tree_depth(TreeNode* root){
        if(root==nullptr) return 0;
        int left=find_tree_depth(root->left);
        int right=find_tree_depth(root->right);
        if(abs(left-right)>1||left==-1||right==-1) return -1;
        return max(left,right)+1;
    }
};

int main(){

}