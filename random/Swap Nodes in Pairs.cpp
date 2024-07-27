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
    ListNode* swapPairs(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode *temp, *root = new ListNode();
    temp = NULL;
        while(head) {
            int f = head->val;
            int s = 0;
            if(head->next == NULL) {
                if(temp == NULL) return head;
                temp->next = head;
                break;
            }
            head = head->next;
            s = head->val;
            head = head->next;
            ListNode *second = new ListNode(s);
            ListNode *first = new ListNode(f);
            if(temp == NULL) temp = second, root = temp;
            else temp -> next = second, temp = temp->next;
            temp->next = first;
            temp = temp->next;
        }
        return root;
    }
};
