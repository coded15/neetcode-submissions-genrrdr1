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
    void reorderList(ListNode* head) {
        vector<int> copyList;
        ListNode* temp = head;
        while (temp != nullptr) {
            copyList.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        for (int i = 0, l = 0, r = copyList.size() - 1; l <= r; i++) {
            if (i % 2 == 0) {
                temp->val = copyList[l];
                l++;
            } else {
                temp->val = copyList[r];
                r--;
            }
            temp = temp->next;
        }
    }
};
