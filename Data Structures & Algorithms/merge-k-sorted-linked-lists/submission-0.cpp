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
    ListNode* mergeTwoSortedLists(ListNode* first, ListNode* second)
    {
        if(!first)
        {
            return second;
        }
        if(!second)
        {
            return first;
        }
        ListNode* temp;
        if(first-> val <= second-> val)
        {
            temp = first;
            first->next = mergeTwoSortedLists(first->next, second);
            first = first->next;
        }
        else
        {
            temp = second;
            second ->next = mergeTwoSortedLists(first, second->next);
            second = second->next;
        }
        return temp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
        {
            return nullptr;
        }
        ListNode* result = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            result = mergeTwoSortedLists(result, lists[i]);
        }
        return result;
    }
};
