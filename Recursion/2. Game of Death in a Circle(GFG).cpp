*************************************************************              SIMILAR TO JOSEPHUS PROBLEM    *************************************************************************
Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
The first and only line of each test case consists of two space separated positive integers denoting n and k.

Output:
Corresponding to each test case, in a new line, print the safe position.

Constraints:
1 ≤ T ≤ 200
1 ≤ n, k ≤ 200

Example:
Input:
3
2 1
4 2
50 10
Output:
2
1
36

Explanation:
Testcase 1: here n = 2 and k = 1, then safe position is 2 as the person at 1st position will be killed.

===================================================================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>v, int k, int index,int &ans)
{
    if(v.size()==1)
    {
        ans = v[0];
        return;
    }
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index,ans);
    return;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vector<int>v;
	    for(int i = 1;i<=n;i++)
	   {
	     v.push_back(i);
	   }
	    int index = 0,ans = -1;
	    k = k-1;
	    solve(v,k,index,ans);
	    cout<<ans<<endl;
	}
	return 0;
}
