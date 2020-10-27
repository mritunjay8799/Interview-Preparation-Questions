Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

===================================================================================================================================================================================

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int size = arr.size();
        int ans;
        for (int i = 0; i < size; i++) 
        { 
           if (arr[abs(arr[i])] >= 0) 
              arr[abs(arr[i])] = -arr[abs(arr[i])]; 
          else
          {
              ans = (abs(arr[i]));
              break;
          }
        } 
        return ans;
    } 
};
