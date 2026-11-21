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
    ListNode* swapPairs(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *prev = nullptr,*temp = head,*temp1;
        head = head->next;
        while(temp != nullptr && temp->next != nullptr){
            temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = temp;
            if(prev != nullptr){
                prev->next = temp1;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};