Example 1:
Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:
Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

=================================================================================================================================================================================
#   MEMOIZATION
    ------------

int t[1001][1001];
int knapSackUtil(int W, int wt[], int val[], int n) 
{ 
    if(n==0 || W==0)
        return 0;
        
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1] <= W)
    {
        t[n][W] = max(val[n-1]+knapSackUtil(W-wt[n-1],wt,val,n-1),knapSackUtil(W,wt,val,n-1));
    }
    else
     t[n][W] = knapSackUtil(W,wt,val,n-1);
     
     int ans = t[n][W];
     return ans;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j<W+1;j++)
            t[i][j] = -1;
    }
    return knapSackUtil(W,wt,val,n);
}

=================================================================================================================================================================================

########      BOTTOM-UP APPROACH
              ------------------
