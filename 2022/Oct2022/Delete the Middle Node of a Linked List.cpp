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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode *temp;
        temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        if(len == 1) return NULL;
        len /= 2;
        ListNode *prev;
        prev = head;
        temp = head;
        while(len--) {
            prev = temp;
            temp = temp->next;
        }
        if(temp->next != NULL) prev->next = temp->next;
        else prev->next = NULL;
        return head;
    }
};

