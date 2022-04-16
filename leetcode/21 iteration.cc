#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1,*p2=list2;
        ListNode *res,*p3;
        int order,val;
        bool first=true;

        res=nullptr;
        while(p1!=nullptr||p2!=nullptr){
            order=0;
            val=105;
            if(p1!=nullptr&&val>p1->val) val=p1->val,order=1;
            if(p2!=nullptr&&val>p2->val) val=p2->val,order=2;

            if(first) first=false,res=p3=new ListNode();
            else{
                p3->next=new ListNode();
                p3=p3->next;
            }

            if(order==1) p3->val=p1->val,p1=p1->next;
            else p3->val=p2->val,p2=p2->next;  
        }
        return res;
    }
};

int main(){
    ListNode l1(1),l2(2),l3(4);
    l1.next=&l2,l2.next=&l3;
    ListNode *p1=&l1;
    ListNode j1(1),j2(3),j3(4);
    j1.next=&j2,j2.next=&j3;
    ListNode *p2=&j1;
    Solution s;
    ListNode *r1=nullptr,*r2=nullptr;
    ListNode* p3=s.mergeTwoLists(r1,r2);
    return 0;
}