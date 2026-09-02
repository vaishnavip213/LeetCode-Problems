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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>ans;
        if (head == NULL){return NULL;}
        ListNode* temp = head;
        while(temp!=NULL){
            int value = temp->val;
            int count = 0;
            // Count how many times this value occurs
            while (temp != NULL && temp->val == value) {
                count++;
                temp = temp->next;
            }
            // Only store values that appeared exactly once
            if (count == 1) {
                ans.push_back(value);
            }
        }
        if (ans.empty()){return NULL;}
        ListNode* newHead = new ListNode(ans[0]);
        temp = newHead;
        int size = ans.size();
        for(int i=1; i<ans.size(); i++){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return newHead;
    }
};