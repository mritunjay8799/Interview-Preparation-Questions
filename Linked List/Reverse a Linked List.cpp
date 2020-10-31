Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

===================================================================================================================================================================================

class Solution {
public:
  ListNode* reverseList(ListNode* head) 
{
  ListNode *curr = head;
  ListNode *next = NULL;
  ListNode *prev = NULL;
  while(curr!=NULL)
  {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }
  head = prev;
  return head;
}
};

===================================================================================================================================================================================

RECURSIVE SOLUTION; 
---------------------


