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

Method 1 : Sort the array using sort method or any Sorting alogorithm.
==========
	
Method 2 : Count the number of 0s, 1s and 2s and re-traverse the array and put 0's first, then 1's and then 2's
==========
	
void sortArr(int arr[], int n) 
{ 
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0; 
  
    // Count the number of 0s, 1s and 2s in the array 
    for (i = 0; i < n; i++) { 
        switch (arr[i]) { 
        case 0: 
            cnt0++; 
            break; 
        case 1: 
            cnt1++; 
            break; 
        case 2: 
            cnt2++; 
            break; 
        } 
    } 
  
    // Update the array 
    i = 0; 
  
    // Store all the 0s in the beginning 
    while (cnt0 > 0) { 
        arr[i++] = 0; 
        cnt0--; 
    } 
  
    // Then all the 1s 
    while (cnt1 > 0) { 
        arr[i++] = 1; 
        cnt1--; 
    } 
  
    // Finally all the 2s 
    while (cnt2 > 0) { 
        arr[i++] = 2; 
        cnt2--; 
    } 

    printArr(arr, n); 
} 
	
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Method 3: 
=========
	
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

