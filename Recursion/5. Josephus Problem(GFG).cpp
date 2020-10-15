Input:
n = 3 k = 2
Output: 3

Input:
n = 5 k = 3
Output: 4

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= k, n <= 20

===================================================================================================================================================================================

void solve(vector<int>v, int index, int k, int &ans)
{
    if(v.size()==1)
    {
        ans = v[0];
        return;
    }
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,index,k,ans);
    return;
}
int josephus(int n, int k)
{
   //Your code here
   vector<int>v;
   for(int i = 1;i<=n;i++)
        v.push_back(i);
    int index = 0;
    int ans = -1;
    k = k-1;
    solve(v,index,k,ans);
    return ans;
}
