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
        // if(!head)
        // {
        //     return nullptr;
        // }
        // // can just do this directly, first we will have to check if head->next is not null
        // // cant have the reversed head set to nullptr in the beginning, because for the case in recursive statck when the node is the tail node, in that case head-> next will be null and the below if condition will not be executed and at the end when we are returning reverse head, we will essentially return null although we should have returned the tail node instead
        // ListNode* reversedHead = head;
        // if(head->next)
        // {
        //     reversedHead = reverseList(head->next);
        //     head->next->next = head;
        //     // dont forget to break this connection, it doesnt matter if you write it inside or outside the if case
        // head->next = nullptr;
        // }
        // return reversedHead;

        // ITERATIVE SOLUTION
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        // return prev here not current
        return prev;
    }
};
