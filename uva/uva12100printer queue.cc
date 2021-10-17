#include<bits/stdc++.h>
using namespace std;
struct node{ //定义一个保留最初位置的结构
    int pow,pos;
    node(int a,int b):pow(a),pos(b){}
};
int main(){
    int a,b,c,d;cin>>a;while(a--){
        cin>>b>>c;
        queue<node> q;
        vector<int> v;
        node t(0,0);
        int cost=0,maxn;
        for(int i=0;i<b;i++) { //用数组保存权值，输入
            cin>>d;
            q.push(node(d,i));
            v.push_back(d);
        }
        int iter=1;
        while(true){
            t=q.front();q.pop(); //出队
            bool go=false; //go来存放队头是否能直接出队列
            for(int i=iter;i<v.size();i++) //若路标以后有大数，就调整
                if(v[i]>t.pow) {
                    q.push(t);
                    v.push_back(t.pow);
                    go=true;
                    break;
                }
            if(!go) { //若没有大数
                cost++; //步数加1
                if(t.pos==c) { //位置为需要的时结束
                    cout<<cost<<endl;
                    break;
                }
            }
            iter++; //数组的路标加1
        }
        cout<<"";
    }
    return 0;
}