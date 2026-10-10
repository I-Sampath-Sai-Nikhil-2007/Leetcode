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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(),i,j;
        if (n==0){
            return nullptr;
        }
        ListNode *temp1 = lists[0];
        while(n>1){
            i=0;
            for (j=0;j+1<n;j+=2){
                lists[i++] = mix(lists[j], lists[j + 1]);
            }
            if (n%2==1){
                lists[i++] = lists[n-1];
            }
        n=i;
        }
        return lists[0];
    }
    ListNode* mix(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};