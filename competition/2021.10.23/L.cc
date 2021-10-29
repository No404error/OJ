#include<bits/stdc++.h> //water
using namespace std;
int main() {
    int T,p;scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&p);
        if(p>18) puts("18");
        else printf("%d\n",p);
    }
    return 0;
}