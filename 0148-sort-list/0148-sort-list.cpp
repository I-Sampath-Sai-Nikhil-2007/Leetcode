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
ListNode* sortList(ListNode* head){
    if (!head || !head->next) return head;
    int n = 0;
    for (ListNode* p = head; p; p = p->next) ++n;
    ListNode dummy(0, head);
    for (int width = 1; width < n; width *= 2) {
        ListNode *curr = dummy.next, *tail = &dummy;
        while (curr) {
            ListNode *left = curr, *right = curr;
            int l = 0, r = 0;
            while (right && l < width) right = right->next, ++l;
            ListNode* after = right;
            while (after && r < width) after = after->next, ++r;
            int i = 0, j = 0;
            while (i < l || j < r) {
                ListNode* pick;
                if (i == l) {
                    pick = right;
                    right = right->next;
                    ++j;
                } else if (j == r || left->val <= right->val) {
                    pick = left;
                    left = left->next;
                    ++i;
                } else {
                    pick = right;
                    right = right->next;
                    ++j;
                }
                tail->next = pick;
                tail = pick;
            }
            curr = after;
        }
        tail->next = nullptr;
    }
    return dummy.next;
}
};