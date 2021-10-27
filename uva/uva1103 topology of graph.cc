#include<bits/stdc++.h>
using namespace std;
const int maxn =205;
map<char,string> mp;
string img1[maxn],img2[maxn],s;
int H,W;
char hol[]="WAKJSD";
void trans(){
    char c[]="0123456789abcdef"; 
    for(int i=0;i<16;i++){
        bitset<4> b(i); //把十进制数改为二进制数
        mp[c[i]]=b.to_string(); //把二进制数改为字符串
    }
}
void dfs(int x,int y,char tag){ //两种模式
    if(tag=='0') {img1[x][y]='0';img2[x+1][y+1]='1';} //tag为0，向img2填充图片，并清理img1的图片
    else img2[x][y]='1'; //tag==1，把img2的白洞涂黑
    int xt,yt,h,w;
    for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++){ //向四周蔓延
        if(!dx&&!dy) continue;
        xt=x+dx;yt=y+dy; 
        h=(tag=='1')?H+2:H; w=(tag=='1')?4*W+2:4*W; //范围
        if(xt>=0&&xt<h&&yt>=0&&yt<w) //未越界
            if((tag=='1'&&img2[xt][yt]=='0')||(tag=='0'&&img1[xt][yt]=='1')) //tag=1且点为0或tag=0且点为1
                dfs(xt,yt,tag);
    }
}
int main(){
    int num=0;
    trans();
    while (cin>>H>>W&&H){
        vector<char> ans;
        for(int i=0;i<H;i++){
            cin>>s;
            img1[i].clear(); //清空
            for(int j=0;j<s.size();j++) img1[i].append(mp[s[j]]); //填充
        }
        for(int i=0;i<H;i++) for(int j=0;j<4*W;j++){
            if(img1[i][j]=='1') for(int i=0;i<H+2;i++) img2[i]=string(4*W+2,'0'); //填充img2
            dfs(i,j,'0');
            int cnt=0; 
            for(int i2=0;i2<H+2;i2++) for(int j2=0;j2<4*W+2;j2++){
                if(img2[i2][j2]=='0') {cnt++;dfs(i2,j2,'1');} //计算img2的白洞数量
            }
            ans.push_back(hol[cnt]);
        }
        sort(ans.begin(),ans.end()); //按字典序来排序
        printf("Case %d: ",++num);
        for(auto p:ans) printf("%c",p);
        printf("\n");
    }
    return 0;
}