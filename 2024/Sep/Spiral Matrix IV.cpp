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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int INF = INT_MAX;
        swap(n, m);
        vector<vector<int>> answer(n, vector<int>(m, INF));
        char direction = 'R';
        int i = 0, j = 0;
        while(head) {
            int val = head->val;
            head = head->next;
            answer[i][j] = val;
            cout << i << " " << j << endl;
            if(direction == 'R') {
                if(j + 1 < m && answer[i][j + 1] == INF) {
                    j++;
                }
                else {
                    direction = 'D';
                    i++;
                }
            }
            else if(direction == 'D') {
                if(i + 1 < n && answer[i + 1][j] == INF) {
                    i++;
                }
                else {
                    direction = 'L';
                    j--;
                }
            }
            else if(direction == 'L') {
                if(j - 1 >= 0 && answer[i][j - 1] == INF) {
                    j--;
                }
                else {
                    direction = 'U';
                    i--;
                }
            }
            else if(direction == 'U') {
                if(i - 1 >= 0 && answer[i - 1][j] == INF) {
                    i--;
                }
                else {
                    direction = 'R';
                    j++;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(answer[i][j] == INF) {
                    answer[i][j] = -1;
                }
            } 
        }
        return answer;
    }
};
