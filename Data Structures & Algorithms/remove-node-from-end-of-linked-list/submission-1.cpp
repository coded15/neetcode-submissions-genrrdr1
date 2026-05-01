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
        int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            length++;
        }
        if(length==1)
        {
            return nullptr;
        }
        int iterations = length -n-1;
        if(iterations==-1)
        {
            return head->next;
        }
        temp = head;
        while(iterations--&& temp)
        {
            temp = temp->next;
        }
        cout << "accessible1";
        ListNode* temp2 = temp->next;
        cout << "accessible2";
        temp->next = temp->next->next;
        cout << "accessible3";
        temp2->next = nullptr;
        cout << "accessible4";
        delete temp2;
        return head;
    }
};
