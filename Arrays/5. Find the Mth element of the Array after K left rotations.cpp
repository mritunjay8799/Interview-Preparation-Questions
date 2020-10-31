Given non-negative integers K, M, and an array arr[] with N elements find the Mth element of the array after K left rotations.

Examples:

Input: arr[] = {3, 4, 5, 23}, K = 2, M = 1
Output: 5
Explanation: 
The array after first left rotation a1[ ] = {4, 5, 23, 3}
The array after second left rotation a2[ ] = {5, 23, 3, 4}
st element after 2 left rotations is 5.

Input: arr[] = {1, 2, 3, 4, 5}, K = 3, M = 2
Output: 5 
Explanation: 
The array after 3 left rotation has 5 at its second position.

===================================================================================================================================================================================

Efficient Approach: To optimize the problem, observe the following points:
----------------------------------------------------------------------------

 If the array is rotated N times it returns the initial array again. 
 
For example, a[ ] = {1, 2, 3, 4, 5}, K=5 then the array after 5 left rotation a5[ ] = {1, 2, 3, 4, 5}. 

Therefore, the elements in the array after Kth rotation is the same as the element at index K%N in the original array.

The Mth element of the array after K left rotations is
 
{ (K + M – 1) % N }th

element in the original array.

===================================================================================================================================================================================

int getFirstElement(int a[], int N, int K, int M)  
{    
    K %= N;    
    int index = (K + M - 1) % N;  
  
    int result = a[index];   
    return result;  
} 
