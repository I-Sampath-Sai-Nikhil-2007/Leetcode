/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp=head,*ptr;
        int i=1;
        while(temp->next!=nullptr){
            i++;
            temp = temp->next;
        }
        k = k%i;
        if(k==0){
            return head;
        }
        temp = head;
        while(k<i-1){
            temp = temp->next;
            k++;
        }
        ptr = temp->next;
        temp->next = nullptr;
        temp = ptr;
        while(ptr->next!=nullptr){
            ptr = ptr->next;
        }
        ptr->next = head;
        return temp;
    }
};