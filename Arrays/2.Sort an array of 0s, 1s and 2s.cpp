Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array inplace in ascending order.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

===================================================================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    int low = 0, mid =0, high = n-1;
    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0: swap(arr[low++],arr[mid++]);
                    break;
            case 1: mid++;
                    break;
            case 2: swap(arr[mid],arr[high--]);
                    break;
        }
    }
    for(int i = 0; i <n;i++)
        cout<<arr[i]<<" ";
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    solve(arr,n);
	    cout<<endl;
	}
	return 0;
}
