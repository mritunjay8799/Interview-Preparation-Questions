You are given a string s. You need to reverse the string.

Example 1:
Input:
s = Geeks
Output: skeeG

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 <= |s| <= 10000

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Method 1 - Using extra space, traverse the array from end and storing values in new vector/string.
==================================================================================================


Method 2 - Using Two Pointer
=============================

string reverseWord(string str){
    
  //Your code here
  int n = str.size();
  int i =0;
  int j = n-1;
  while(i<=j)
  {
      swap(str[i],str[j]);
      i++;
      j--;
  }
  return str;
}
