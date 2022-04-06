#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        //度数表
        vector<int> degree(n);
        //邻接表
        map<int,vector<int>> g;

        for(int i=0;i<edges.size();i++){
            //弧的头和尾
            int u=edges[i][0],v=edges[i][1];
            degree[u]++;degree[v]++;
            g[u].push_back(v);g[v].push_back(u);
        }
        vector<int> res;
        queue<int> q;

        //度数为1的节点入队
        for(int i=0;i<n;i++) if(degree[i]==1) q.push(i);

        while (!q.empty()){
            res.clear();
            int size=q.size();
            for(int i=0;i<size;i++){
                int u=q.front();q.pop();
                res.push_back(u);
                degree[u]--;
                for(auto v:g[u]){
                    degree[v]--;
                    if(degree[v]==1) q.push(v);
                }
            }
        }
        return res;
    }
};