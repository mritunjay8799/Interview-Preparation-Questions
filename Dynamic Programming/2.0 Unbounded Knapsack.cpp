Given a set of N items, each with a weight and a value, and a weight limit W. 
Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W) 

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

===================================================================================================================================================================================

int dp[1001][1001];
class Solution{
public:
int solve(int N, int W, int val[], int wt[])
{
    for(int i = 1;i<N+1;i++)
    {
        for(int j = 1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][W];
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1, sizeof(dp));                  #initializing the matrix with -1
        for(int i =0;i<N+1; i++)                    #updating values if either N=0 or W = 0
            dp[i][0] = 0;
        for(int i =0;i<W+1; i++)
            dp[0][i] = 0;
        int res = solve(N,W,val,wt);
        return res;
    }
};
================================================================================================================================================================================

MEMOIZED CODE:-
--------------

