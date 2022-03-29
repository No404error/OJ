#include<iostream>
#include<string>
#include<cstring>
#include<set>
using namespace std;

//邻接矩阵
bool graph[28][28];
//按字典序记录出现的元素
int order[28];
//判断order[i]是否被访问的数组
bool vis[28];
//记录order[i]在串中位置
int pos[28];
//记录串和结果
int resq[28],res[28];
//筛顺序
set<int> s;
//结果值
int sum;

//cur为当前已经遍历节点数，temp为当前序列的带宽
void dfs(int cur,int temp){
    //base case
    if(cur==s.size()) {
        if(temp<sum) {
            //把答案存下来
            sum=temp;
            memcpy(res,resq,sizeof(res));
        }
        return;
    }

    for(int i=0;i<s.size();i++){
        if(vis[i]) continue;

        
        int dis=0;
        for(int j=0;j<s.size();j++){
            if(j==i) continue;
            if(vis[j]&&(graph[order[j]][order[i]]||graph[order[i]][order[j]])) dis=max(dis,cur-pos[j]);
        }
        if(dis>sum) continue;

        pos[i]=cur;
        vis[i]=true;
        resq[cur]=order[i];
        dfs(cur+1,dis>temp?dis:temp);
        vis[i]=false;
    }
    return;
}
int main(){
    string buf;
    while(getline(cin,buf)&&buf!="#"){
        //初始化
        memset(graph,0,sizeof(graph));
        memset(vis,0,sizeof(vis));
        s.clear();
        sum=30;

        //建立邻接矩阵
        int val,start;
        start=buf[0]-'A';
        s.insert(start);
        for(int i=1;i<buf.size();i++){
            if(buf[i]==';') start=buf[++i]-'A',s.insert(start);
            else if(buf[i]==':') continue;
            else{
                val=buf[i]-'A';
                s.insert(val);
                graph[start][val]=true;
            }
        }
        
        //字典序升序存索引
        auto iter=s.begin();
        for(int i=0;i<s.size();i++,iter++) order[i]=*iter;

        dfs(0,0);
        for(int i=0;i<s.size();i++) printf("%c ",'A'+res[i]);
        printf("-> %d\n",sum);
    }
    return 0;
}