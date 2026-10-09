/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null){
            return false;
        }
        Map<ListNode, Integer> indexes = new HashMap<>();
        int i=0;
        while(!(indexes.containsKey(head))){
            indexes.put(head, i++);
            if(head.next == null){
                return false;
            }
            head = head.next;
        }
        return true;
    }
}