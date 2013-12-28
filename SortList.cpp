

Sort List Total Accepted: 2328 Total Submissions: 12833 My Submissions
Sort a linked list in O(n log n) time using constant space complexity.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head)
    {
        return splitMerge(head);
    }
    
    //out: newHead
    ListNode *splitMerge(ListNode *node)
    {
        if(!node || !node->next)
            return node;
            
        ListNode *midP = findMidInList(node);
        ListNode *h1 = splitMerge(node);
        ListNode *h2 = splitMerge(midP);
        ListNode *h = mergeSortLists(h1, h2);
        return h;
    }
    
    //out: newHead
    ListNode * mergeSortLists(ListNode *h1, ListNode *h2)
    {
        if(!h1)
            return h2;
        else if(!h2)
            return h1;
            
        ListNode *newHead, *tmp, *nx;
        newHead = tmp = NULL;
        
        while(h1 && h2)
        {
            if(h1->val < h2->val)
            {
                nx = h1;
                h1 = h1->next;
            }
            else
            {
                nx = h2;
                h2 = h2->next;
            }
            
            if(!newHead)
            {
                newHead = tmp = nx;
            }
            else
            {
                tmp->next = nx;
                tmp = tmp->next;
            }
        }
        
        if(h1)
        {
            tmp->next = h1;
        }
        
        if(h2)
        {
            tmp->next = h2;
        }
        
        return newHead;
        
    }
    
    //in: head
    //out: mid pointer
    //The key part to set next of the node before mid to NULL
    //This makes the list split into two sperate ones
    ListNode *findMidInList(ListNode *node)
    {
        if(!node || !node->next)
            return node;
            
        ListNode *p1, *p2, *pre;
        p1 = p2 = node;
        while(p2 && p2->next)
        {
            pre = p1;
            p1 = p1->next;
            
            p2 = p2->next->next;
        }
        pre->next = NULL;
        
        return p1;
    }
};