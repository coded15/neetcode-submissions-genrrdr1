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
    ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        // can just do this directly, first we will have to check if head->next is not null
        ListNode* reversedHead = head;
        if(head->next)
        {
            reversedHead = reverseList(head->next);
            head->next->next = head;
            // dont forget to break this connection
        }
            head->next = nullptr;
        return reversedHead;
        // while(head!=nullptr)
        // {
        //     ListNode temp = head->next->next;
        //     head->next->next = head;
        //     temp->next = head;
        //     head = head->next;
        // }
    }
};
