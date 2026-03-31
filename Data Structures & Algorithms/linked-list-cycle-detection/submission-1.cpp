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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> countAddress;
        // ahh forgot again and put here !head.
        while(head)
        {
            if(countAddress[head] == 1)
            {
                return true;
            }
            countAddress[head]++;
            head = head->next;
        }
        return false;
    }
};
