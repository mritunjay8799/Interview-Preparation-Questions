Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. 
  The output should be printed in sorted increasing order of strings

Example 1:
Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
 
Expected Time Complexity: O(2^n)

==================================================================================================================================================================================
  
class Solution{
public:
    void solve(string ip, string op, vector<string>&res)
    {
        if(ip.size()==0)
        {
            res.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        
        op1.push_back(' ');
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,res);
        solve(ip,op2,res);
    }
    vector<string> permutation(string S){
        string op = "";
        op = S[0];
        vector<string>res;
        S.erase(S.begin()+0);
        solve(S,op,res);
        return res;
    }
};
