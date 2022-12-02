#include<bits/stdc++.h>
using namespace std;


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
    //dp[0]为通过i的最大的路径和,dp[1]为不通过i的最大路径和,dp[2]为通过i的单侧最大路径和
    int dp[3];
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max(dp[0],dp[1]);
    }

    void dfs(TreeNode* root){
        int l0,l1,l2,r0,r1,r2;

        if(root->left==nullptr)
            l0=l1=l2=-2000;
        else{
            dfs(root->left);
            l0=dp[0];
            l1=dp[1];
            l2=dp[2];
        }

        if(root->right==nullptr)
            r0=r1=r2=-2000;
        else{
            dfs(root->right);
            r0=dp[0];
            r1=dp[1];
            r2=dp[2];
        }

        dp[0]=root->val+max(0,l2)+max(0,r2);
        dp[1]=max(max(l0,l1),max(r0,r1));
        dp[2]=root->val+max(0,max(l2,r2));
    }
};

int main(){
    TreeNode t31(7);
    TreeNode t32(2);
    TreeNode t33(1);
    TreeNode t21(11,&t31,&t32);
    TreeNode t22(13);
    TreeNode t23(4,nullptr,&t33);
    TreeNode t11(4,&t21,nullptr);
    TreeNode t12(8,&t22,&t23);
    TreeNode t0(5,&t11,&t12);
    Solution s;
    cout<<s.maxPathSum(&t0);
    return 0;
}