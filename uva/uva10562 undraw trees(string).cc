#include<bits/stdc++.h>
using namespace std;
vector<string> v; //二维数组
string s; 
void dfs(int r,int c){ //遍历输出
    cout<<v[r][c]<<"("; //本次dfs输出
    if(r+1<v.size()&&v[r+1][c]=='|'){ //是否有子树
        int l=c;
        while(v[r+2][l]=='-') l--;
        for(int i=l+1;i<v[r+2].size()&&v[r+2][i]=='-';i++){ //找出所有子树
            if(i<v[r+3].size()&&v[r+3][i]!=' ') dfs(r+3,i);
        }
    }
    cout<<")";
}
int main(){
    int T;scanf("%d",&T);getchar(); //清理结束字符
    while(T--){
        v.clear();
        while(getline(cin,s)&&s[0]!='#') v.push_back(s); //输入一行
        cout<<"("; //初始括号
        if(v.size()>0) for(int i=0;i<v[0].size();i++) if(v[0][i]!=' ') { dfs(0,i);break;} //找到根
        cout<<")\n";
    }
    return 0;
}