#include<bits/stdc++.h>
using namespace std;
struct Node{ //节点
    bool have_value; //记录节点是否被赋值过
    int v; //值
    Node *left,*right; //左子树和右子树
    Node():have_value(false),left(NULL),right(NULL){} //构造函数
};
const int maxn=20; 
vector<int> ans; 
char s[maxn];
bool failed; //记录可能的错误信息
Node* root; //根
Node* newnode(){return new Node();} //创建新节点
void addnode(int v,char* s){ //添加节点
    int n=strlen(s); //访问层数
    Node* u=root; 
    for(int i=0;i<n;i++) //寻找要添加的节点位置
        if(s[i]=='L') {
            if(u->left==NULL) u->left=newnode(); //无路径，添加
            u=u->left;
        } 
        else if(s[i]=='R'){
            if(u->right==NULL) u->right=newnode();
            u=u->right;
        }
        if(u->have_value) failed=true; //错误信息：被重复赋值
        u->v=v; //添加信息
        u->have_value=true;
}
bool read_input(){
    failed=false; //初始化错误信息
    root =newnode(); //根初始化
    for(;;){
        if(scanf("%s",s)!=1) return false; //遇到eof就返回false
        if(!strcmp(s,"()")) break; //遇到结束符结束
        int v;
        sscanf(&s[1],"%d",&v); //把路径和值分开
        addnode(v,strchr(s,',')+1); //添加节点
    }
    return true;
}
bool bfs(vector<int>& ans){ //ans结果数组
    queue<Node*> q;
    ans.clear(); //清空ans数组
    q.push(root); 
    while(!q.empty()){
        Node* u=q.front();q.pop();
        if(!u->have_value) return false; //错误信息：路径不完善
        ans.push_back(u->v); //记录值
        if(u->left!=NULL) q.push(u->left); //左节点入栈
        if(u->right!=NULL) q.push(u->right); //右节点入栈
    }
    return true;
}
void remove_tree(Node* u){ //内存管理
    if(u==NULL) return; //递归终止条件
    remove_tree(u->left); //左子树入栈
    remove_tree(u->right); //右子树入栈
    delete u; //删除节点
}
int main(){
    while(read_input()){ //读数据
        if(bfs(ans)&&!failed){  //如果没有错误且遍历成功 输出ans数组
            printf("%d",ans[0]);
            for(int i=1;i<ans.size();i++) printf(" %d",ans[i]);
        }
        else printf("not complete"); //输出字符串
        printf("\n");
        remove_tree(root); //删除树
    }
    return 0;
}