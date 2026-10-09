/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode temp = list2;
        for (;temp!=null;temp=temp.next){
            list1 = insert(list1,temp.val);
        }
        return list1;
    }
    ListNode insert(ListNode list1,int v){
        if(list1 == null || v < list1.val){
            ListNode f = new ListNode(v,list1);
            return f;
        }
        ListNode temp2 = list1;
        while (temp2.next!=null && temp2.next.val<=v){
            temp2=temp2.next;
        }
        ListNode ptr1 = new ListNode(v,temp2.next);
        temp2.next = ptr1;
        return list1;
    }
}