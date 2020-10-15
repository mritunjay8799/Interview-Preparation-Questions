Given a stack with push(), pop(), empty() operations, delete the middle of it without using any additional data structure.
Middle: ceil(size_of_stack/2.0)
 
Example 1:
Input: 
Stack = {1 2 3 4 5}
Output:
ModifiedStack = {1 2 4 5}

Example 2:
Input: 
Stack = {1 2 3 4}
Output:
ModifiedStack = {1 3 4}

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= sizeOfStack <= 100

===================================================================================================================================================================================

void helper(stack<int>&s,int sizeOfStack,int current)
{
    if(current > sizeOfStack)
   {
       return;
   }
   int val = s.top();
   s.pop();
   sizeOfStack = s.size();
   current +=1;
   helper(s,sizeOfStack,current);
   if(sizeOfStack+1 == current || sizeOfStack+2 == current)
    {}
    else
        s.push(val);
   return;
}
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
   {
       helper(s,sizeOfStack,current);
       return s;
   }

