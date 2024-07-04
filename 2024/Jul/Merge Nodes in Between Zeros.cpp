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
    ListNode* mergeNodes(ListNode* head) {
	    ListNode *temp, *root = new ListNode();
	    temp = root = NULL;
	    int sum = 0;
	    head = head->next;
	    while(head != NULL) {
		    int value = head->val;
		    sum += value;
		    if(value == 0) {
			    ListNode *newNode = new ListNode(sum);
			    sum = 0;
			    if(root == NULL) {
				    root = newNode;
				    temp = root;
			    }
			    else {
				    root->next = newNode;
				    root = root->next;
			    }
		    }
		    head = head->next;
	    }
	    return temp;

    }
};
