Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:
Input:  N = 3
Output: 111 110 101

Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20

====================================================================================================================================================================================

class Solution{
public:	

    void solve(vector<string>&v, int ones, int zeroes,string op, int N)
    {
        if(N==0)
        {
            v.push_back(op);
            return;
        }
        if(ones>zeroes)
        {
            string op1 = op;
            string op2 = op;
            op1.push_back('1');
            op2.push_back('0');
            solve(v,ones+1,zeroes,op1,N-1);
            solve(v,ones,zeroes+1,op2,N-1);
        }
        else
        {
            string op1 = op;
            op1.push_back('1');
            solve(v,ones+1,zeroes,op1,N-1);
        }
        return;
    }

	vector<string> NBitBinary(int N)
	{
	    int ones = 0,zeroes = 0;
	    string op = "";
	    vector<string>v;
	    solve(v,ones,zeroes,op,N);
	    return v;
	}
};
