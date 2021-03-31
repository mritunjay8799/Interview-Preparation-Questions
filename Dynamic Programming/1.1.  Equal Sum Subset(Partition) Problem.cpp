Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:
Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be partitioned into two such parts.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

=================================================================================================================================================================================

MEMOIZED CODE-
---------------

int t[101][1000001];
class Solution{
public:
    int solve(int N, int arr[], int sum)
    {
        if(N==0 && sum!=0)
            t[N][sum] =  0;
        if(sum==0)
            t[N][sum] = 1;
            
        if(t[N][sum]!=-1)
            return t[N][sum];
        
        if(arr[N-1]<=sum)
            t[N][sum] =  solve(N-1,arr,sum-arr[N-1]) || solve(N-1,arr,sum);
        else if(arr[N-1] > sum)
            t[N][sum] = solve(N-1,arr, sum);
        
        return t[N][sum];
        
    }
    
    int equalPartition(int N, int arr[])
    {
    
        int sum = 0;
        for(int i = 0;i<N;i++)
            sum+=arr[i];
        if(sum%2!=0)
           return 0;
        sum = sum/2;
        memset(t,-1,sizeof(t));
        int ans = solve(N,arr,sum);
        return ans;
    }
};

=================================================================================================================================================================================

TABULAR METHOD CODE-
--------------------

int dp[201][200001];
class Solution {
public:
    int solve(vector<int>nums, int n, int sum)
    {
        int i,j;
        for(i = 1;i<n+1;i++)
        {
            for(j = 1;j<sum+1;j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i= 0; i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sum = sum/2;
        for(int i = 0;i<sum+1;i++)
            dp[0][i] = 0;
        for(int i = 0;i<n+1;i++)
            dp[i][0] = 1;
        return solve(nums,n,sum);
    }
};    
