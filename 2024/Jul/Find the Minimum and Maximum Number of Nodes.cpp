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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        vector<int> answer(2, -1);
        int previous = 0;
        if(head == NULL || head->next == NULL) return answer;
        previous = head->val;
        int pre = previous;
        head = head->next;
        int nodeNumber = 1;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int next = 0;
        int last = -1;
        while(head) {
            int value = head->val;
            if(head->next != NULL) next = head->next->val;
            else break;
            if((value > pre && value > next) || (value < pre && value < next)) {
                if(last == -1) last = nodeNumber;
                else mx = nodeNumber, mn = min(mn, nodeNumber - previous);
                previous = nodeNumber;
            } 
            head = head->next;
            pre = value;
            nodeNumber++;
        }
        if(mn == INT_MAX || mx == INT_MIN) return answer;
        cout << last << " " << mx << endl;
        answer[0] = mn;
        answer[1] = mx - last;
        return answer;
    }
};
