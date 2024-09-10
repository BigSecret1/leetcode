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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *newHead, *answer = new ListNode();
        newHead = NULL;
        while(head) {
            int curValue = head->val;
            ListNode *currNode = new ListNode(curValue);
            int nextValue = -1;
            if(newHead == NULL) {
                newHead = currNode;
                answer = newHead;
            }
            else {
            newHead->next = currNode;
            newHead = newHead->next;
            }
            if(head -> next) {
                nextValue = head->next->val;
                int gcd = Gcd(curValue, nextValue);
                ListNode *temp = new ListNode(gcd);
                newHead->next = temp;
                newHead = newHead -> next;
            }
            head = head->next;
        }
        return answer;
    }

    int Gcd(int a, int b) {
        if(a == 0) return b;
        return Gcd(b % a, a);
    }
};
