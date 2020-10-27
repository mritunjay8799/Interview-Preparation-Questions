Given a binary array A[] of size N. The task is to arrange array in increasing order(inplace).

Constraints:
1 < = T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
5
1 0 1 1 0
10
1 0 1 1 1 1 1 0 0 0

Output:
0 0 1 1 1
0 0 0 0 1 1 1 1 1 1

=================================================================================================================================================================================
void solve(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        switch(arr[low])
        {
            case 0: low++;
                    break;
            case 1: swap(arr[low],arr[high--]);
                    break;
        }
    }
    for(int i = 0; i <n;i++)
        cout<<arr[i]<<" ";
}
================================================================================================================================================================================
#
1. Take two pointer type0(for element 0) starting from beginning (index = 0) and type1(for element 1) 
   starting from end (index = array.length-1).
Initialize type0 = 0 and type1 = array.length-1
2. It is intended to Put 1 to the right side of the array. Once it is done, then 0 will definitely towards left side of array.
#

void segregate0and1(int arr[],  
                    int size) 
{ 
    int type0 = 0; 
    int type1 = size - 1; 
      
    while(type0 < type1) 
    { 
        if(arr[type0] == 1) 
        { 
            swap(arr[type0],  
                 arr[type1]); 
            type1--; 
        } 
        else
        type0++; 
    } 
} 
