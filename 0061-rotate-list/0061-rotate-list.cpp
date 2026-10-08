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
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or only one node
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Find length and last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Reduce unnecessary rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Make the list circular
        tail->next = head;

        // Find new tail
        ListNode* newTail = head;

        for (int i = 1; i < n - k; i++) {
            newTail = newTail->next;
        }

        // New head is after new tail
        head = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return head;
    }
};