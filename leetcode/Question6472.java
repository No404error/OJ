import java.util.List;

public class Question6472 {
    public static void main(String[] args) {
        ListNode l5=new ListNode(8);
        ListNode l4=new ListNode(3,l5);
        ListNode l3=new ListNode(13,l4);
        ListNode l2=new ListNode(2,l3);
        ListNode l1=new ListNode(5,l2);
        Solution solution=new Solution();
        ListNode rl=solution.removeNodes(l1);
        System.out.println();
    }
}


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }


class Solution {
    public ListNode removeNodes(ListNode head) {
        ListNode headR=reverseList(head);
        ListNode tmpNode=headR.next;
        ListNode lastNode=headR;

        int maxVal= headR.val;
        while(tmpNode!=null){

            if(tmpNode.val<maxVal){
                //delete tmpNode, and lastNode don't change
                lastNode.next=tmpNode.next;
            }
            else{
                if(tmpNode.val>maxVal)
                    maxVal= tmpNode.val;
                lastNode=tmpNode;
            }

            //tmp must change
            tmpNode=tmpNode.next;
        }

        return reverseList(headR);
    }

    //将列表反转
    public ListNode reverseList(ListNode head){
        ListNode tail=new ListNode(head.val,null);
        head=head.next;
        while (head!=null){
            ListNode node=new ListNode(head.val,tail);
            tail=node;
            head=head.next;
        }
        return tail;
    }
}