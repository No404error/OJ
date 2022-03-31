#include<iostream>
#include<map>
using namespace std;



//  Definition for a binary tree node.
struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
class Solution {
public:
    double minimalExecTime(TreeNode* root) {
        return dfs(root).second;
    }
    pair<int,double> dfs(TreeNode* root){
        if(!root) return{0,0.0};
        auto left=dfs(root->left);
        auto right=dfs(root->right);
        int a=left.first,c=right.first;
        double b=left.second,d=right.second;
        return {a+c+root->val,(a>=c?max((a+c)/2.0,b):max((a+c)/2.0,d))+root->val};
    }
};

int main(){

    return 0;
}