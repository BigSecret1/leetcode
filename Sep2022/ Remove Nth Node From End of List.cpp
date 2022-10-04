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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr, *prev, *nxt;
        prev = NULL;
        curr = head;
        nxt = NULL;
        ListNode *temp;
        temp = head;
        int cnt = 0;
        while(temp != NULL) cnt++, temp = temp->next;
        if(cnt < 2) return NULL;
        temp = head;
        int cnt2 = 0;
        while(cnt2 <= (cnt - n + 1)) {
            cnt2++;
            if(cnt2 == (cnt - n + 1)) {
                if(prev == NULL) {
                   curr = head->next;
                    break;
                }
                else if(temp->next == NULL) {
                    temp = NULL;
                    prev->next = temp;
                    break;
                }
                else {
                    prev->next = temp->next;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        return curr;
    }
};
