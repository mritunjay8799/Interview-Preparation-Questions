Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.

Example 1:

Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()

Expected Time Complexity: O(2^N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

Constraints:
1 ≤ N ≤ 12
  
===================================================================================================================================================================================
  
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends


//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
void solve(int on, int cn, vector<string>&v, string op)
{
    if(on==0&&cn==0)
    {   v.push_back(op);
        return;
    }
    if(on!=0 && on<cn)
    {
        string op1 = op;
        string op2 = op;
        op1.push_back('(');
        op2.push_back(')');
        solve(on-1,cn,v,op1);
        solve(on,cn-1,v,op2);
    }
    else if(on==cn)
    {
        string op2=op;
        op2.push_back('(');
        solve(on-1,cn,v,op2);
    }
    else if(on==0 && cn!=0)
    {
        string op2=op;
        op2.push_back(')');
        solve(on,cn-1,v,op2); 
    }
    return;
}
vector<string> AllParenthesis(int n) 
{
    int on = n-1;
    int cn = n;
    vector<string>v;
    string op="(";
    solve(on,cn,v,op);
    return v;
}

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> result = AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
