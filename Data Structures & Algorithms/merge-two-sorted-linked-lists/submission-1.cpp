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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* head1 = list1;
        // ListNode* head2 = list2;
        // while(list1 || list2)
        // {
        //     if(list1->val<=list2->val)
        //     {
        //         head1 = list1->next;
        //         list1->next = list2;
        //         // you cant just insert that node in the beginning of the second list, you will have to find the correct postition of that node in the list
        //         list2 = list1;
        //         list1 = head1;
        //     }
        //     else
        //     {
        //         head2 = list2->next;
        //         list2->next = list1;
        //         list1 = list2;
        //         list2 = head2;
        //     }
        // }
        // if(!list1)
        // {
        //     return head2;
        // }
        // return head1;


        // ListNode* finalHead = list1;
        // ListNode* temp;
        // following has to be an and condition not an or condition.
        // while(list1 || list2)
        // {
        //     if(list1-> val <= list2->val)
        //     {
        //         list1 = list1->next;
        //     }
        //     else
        //     {
        //         temp = list1->next;
        //         list2 = list2->next;
        //         ListNode insert(list2->val, temp);
        //         list1->next = insert;
        //     }
        // }


    //     ListNode dummy(0);
    //     ListNode* tempNode = &dummy;
    //     while(list1 && list2)
    //     {
    //         if(list1->val <= list2 -> val)
    //         {
    //             tempNode->next = list1;
    //             list1 = list1->next;
    //         }
    //         else
    //         {
    //             tempNode->next = list2;
    //             list2 = list2->next;
    //         }
    //         tempNode = tempNode->next;
    //     }
    //     if(list1)
    //     {
    //         tempNode->next = list1;
    //     }
    //     else
    //     tempNode->next = list2;
    //     return dummy.next;
    // }


    if(!list1)
    {
        return list2;
    }
    if(!list2)
    {
        return list1;
    }
    ListNode* temp;
    if(list1->val <= list2->val)
    {
        temp = list1;
        list1->next = mergeTwoLists(list1->next, list2);
        list1 = list1->next;
    }
    else
    {
        temp = list2;
        list2->next = mergeTwoLists(list1, list2->next);
        list2 = list2->next;
    }
    return temp;
    }
};
