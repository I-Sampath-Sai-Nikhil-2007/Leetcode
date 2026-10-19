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
    void reorderList(ListNode* head) {
        ListNode *temp = head,*ptr = head,*ptr1;
        while(ptr->next!=nullptr && ptr->next->next!=nullptr){
            while(ptr->next != nullptr){
                ptr1 = ptr;
                ptr = ptr->next;
            }
            ptr->next = temp->next;
            temp->next = ptr;
            ptr1->next = nullptr;
            if(temp->next == nullptr){
                return;
            }
            temp = temp->next->next;
            ptr = temp;
        }
    }
};