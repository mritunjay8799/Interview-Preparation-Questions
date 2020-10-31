Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

===================================================================================================================================================================================

METHOD 1 (Use a Stack)

-> A simple solution is to use a stack of list nodes. This mainly involves three steps.
-> Traverse the given list from head to tail and push every visited node to stack.
-> Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
-> If all nodes matched, then return true, else false.

===================================================================================================================================================================================

METHOD 2 (By reversing the list)
This method takes O(n) time and O(1) extra space.
1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it back to the first half.

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return 1;
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)
                return 1;
            return 0;
        }
        ListNode* slow= head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverse(slow->next);
        while(temp!=NULL && head!=NULL)
        {
            if(temp->val!=head->val)
                return 0;
            temp = temp->next;
            head = head->next;
        }
        return 1;
    }
};

================================================================================================================================================================================

RECURSION: 
-----------

class Solution {
public:

    bool isPalindromeUtil(ListNode** left, ListNode* right)  
{  
    if (right == NULL)  
        return true;  

    bool isp = isPalindromeUtil(left, right->next);  
    if (isp == false)  
        return false;  
    
    bool isp1 = (right->val == (*left)->val);  
    *left = (*left)->next;  
  
    return isp1;  
} 
   
    bool isPalindrome(ListNode* head) {
        
        ListNode* left = head;
        ListNode* right = head;
        return isPalindromeUtil(&left, right);
    }
};
