#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,x,y;
    vector<int> X,Y; 
    while(scanf("%d",&k)==1){ //EOF结束
        X.clear();Y.clear(); //清空答案序列
        for(int y=1;y<=2*k;y++){ //遍历
            if(y==k) continue; //剔除错误情况
            x=k*y/(y-k); //得到x
            if(x>=y&&(x*y==k*(x+y))){ //判断是否可行
                X.push_back(x);
                Y.push_back(y);
            }
        }
        printf("%d\n",X.size()); //输出
        for(int i=0;i<X.size();i++) printf("1/%d = 1/%d + 1/%d\n",k,X[i],Y[i]);
    }
    return 0;
}