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
        int tot = 0;

        ListNode* tmp = head;

        while(tmp) {
            tot++;
            tmp = tmp->next;
        }

        int cur = tot - n;

        // If first node needs to be deleted
        if(cur == 0) {
            return head->next;
        }

        tmp = head;

        // Reach the node just before the one to delete
        while(cur > 1) {
            tmp = tmp->next;
            cur--;
        }

        // Skip the nth node from the end
        tmp->next = tmp->next->next;

        return head;
    }
};
