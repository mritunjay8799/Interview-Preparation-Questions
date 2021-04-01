Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such 
that the absolute difference between their sums is minimum and find the minimum difference

Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1   
  
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 10^6

==================================================================================================================================================================================

RECURSIVE APPROACH :
-------------------
  
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal)
{
	if (i==0)
		return abs((sumTotal-sumCalculated) - sumCalculated);

	return min(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal),
			findMinRec(arr, i-1, sumCalculated, sumTotal));
}

int findMin(int arr[], int n)
{
	// Compute total sum of elements
	int sumTotal = 0;
	for (int i=0; i<n; i++)
		sumTotal += arr[i];

	return findMinRec(arr, n, 0, sumTotal);
}

int main()
{
	int arr[] = {3, 1, 4, 2, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The minimum difference between two sets is "
		<< findMin(arr, n);
	return 0;
}

  
  
TOP - DOWN (TABULAR METHOD) :
------------------------------
  
int t[10001][100000001];
class Solution{
	public:
    vector<int> subset_sum(int arr[], int n, int sum)
    {
        t[n+1][sum+1];
        vector<int>v;
        memset(t,-1,sizeof(t));
        for(int i = 0;i<sum+1;i++)
            t[0][i] = 0;
        for(int i = 0;i<n+1;i++)
            t[i][0] = 1;
        for(int i =1;i<n+1;i++)
        {
            for(int j = 1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        for(int i = 0;i<=sum/2;i++)
            v.push_back(t[n][i]);
        return v;
    }
	int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int sum;
	    for(int i =0;i<n;i++)
	        sum+=arr[i];
	   vector<int>res;
	   res = subset_sum(arr,n,sum);
	   int ans = INT_MAX;
	   for(int i =0;i<res.size();i++)
	   {
	       ans = min(ans,(sum-2*res[i]));
	   }
	   return ans;
	} 
};
