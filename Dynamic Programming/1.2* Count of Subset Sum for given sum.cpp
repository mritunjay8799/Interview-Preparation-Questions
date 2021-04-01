Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 10^9+7

Example 1:
Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
             {2, 3, 5}
Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
  
=================================================================================================================================================================================
  
TABULAR METHOD :
---------------
  
int t[10001][100000001];
class Solution{
    public:
    int solve(int arr[],int n,int sum)
    {
        for(int i =1;i<n;i++)
        {
            for(int j = 1;j<sum;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]]+t[i-1][j])%1000000007;
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n-1][sum-1];
    }
  
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int t[n+1][sum+1];
        memset(t,0,sizeof(t));
        for(int j =0;j<sum+1;j++)
        {
            t[0][j] = 0;        
        }
        for(int i =0;i<n+1;i++)
        {
            t[i][0] = 1;
        }
        return solve(arr,n+1,sum+1);
    }
};

================================================================================================================================================================================
  
MEMOIZED CODE:
--------------
