Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

Expected Time Complexity : O(N*N)
Expected Auixilliary Space : O(N) recursive.

===================================================================================================================================================================================

void insert(stack<int>&s, int temp)
{
    if(s.empty() || temp>=s.top())
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}

void SortedStack :: sort()
{
   //Your code here
    if(s.size()==1)
        return;
    int temp = s.top();
    s.pop();
    sort();
    insert(s,temp);
    return;
}
