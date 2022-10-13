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
    void deleteNode(ListNode* node) {
        ListNode *prev;
        while(true) {
            if(node->next == NULL) {
                prev -> next = NULL;
                break;
            }
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
    }
};

