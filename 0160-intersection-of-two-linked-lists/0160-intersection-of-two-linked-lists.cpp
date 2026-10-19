/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA,*temp2=headB;
        int a=1,b=1,d;
        while(temp1->next!=nullptr){
            temp1 = temp1->next;
            a++;
        }
        while(temp2->next!=nullptr){
            temp2 = temp2->next;
            b++;
        }
        temp1 = headA,temp2 = headB;
        if(a>b){
            while(a!=b){
                temp1 = temp1->next;
                a--;
            }
        }
        else if(b>a){
            while(b!=a){
                temp2 = temp2->next;
                b--;
            }
        }
        while(temp1 != temp2){
            if(temp1->next == nullptr || temp2->next == nullptr){
                return nullptr;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};