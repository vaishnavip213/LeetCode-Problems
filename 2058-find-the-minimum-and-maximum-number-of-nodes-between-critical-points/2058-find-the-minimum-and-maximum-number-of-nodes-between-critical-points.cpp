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
        if (head == nullptr || head->next == nullptr || 
            head->next->next == nullptr) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int pos = 2;

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = INT_MAX;

        while (next != nullptr) {

            // Check if curr is a local maximum or minimum
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = pos;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, pos - lastCritical);
                }

                // Update last critical point
                lastCritical = pos;
            }

            // Move forward
            prev = curr;
            curr = next;
            next = next->next;

            pos++;
        }

        // Fewer than 2 critical points
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};