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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
            unordered_map<int, int> mp;
       for(auto it : nums) {
        mp[it] = 1;
       }
       ListNode *answer, *root = new ListNode();
       root = NULL;
       while(head) {
        int val = head->val;
        ListNode *temp = new ListNode(val);
        if(mp.find(val) == mp.end()) {
            if(root == NULL) {
                root = temp;
                answer = root;
            }
            else {
                root -> next = temp;
                root = root->next;
            }
        }
        head = head->next;
       }
       return answer;
    }
};

