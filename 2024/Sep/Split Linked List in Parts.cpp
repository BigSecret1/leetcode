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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> arr;
        vector<ListNode*> answer;
        while(head) {
            int val = head->val;
            arr.push_back(val);
            head = head->next;
        }
        int n = arr.size();
        int part = n / k;
        if(n <= k) {
            for(auto it : arr) {
                ListNode *temp = new ListNode(it);
                answer.push_back(temp);
            }
            while(answer.size() < k) {
                ListNode *temp = new ListNode();
                temp = NULL;
                answer.push_back(temp);
            }
            return answer;
        }
        int extra = n % k;
        while(answer.size() < k) {
            ListNode* root, *start = new ListNode();
            root = NULL; 
            int cnt = 0;
            for(auto it : arr) {
                ListNode* temp = new ListNode(it);
                if(root == NULL) {
                    root = temp;
                    start = root;
                }
                else {
                    root->next = temp;
                    root = root-> next;
                }
                cnt++;
                if(cnt >= part) {
                    if(extra && cnt == part) continue;
                        answer.push_back(start);
                        if(extra) extra--;
                        cnt = 0;
                        root = NULL;
                        start = NULL;
                }
            }
        }
        return answer;
    }
};
