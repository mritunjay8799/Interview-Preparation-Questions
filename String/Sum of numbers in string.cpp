Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123

===================================================================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

int sum(string str)
{
    string temp = "";
    int sum = 0;
    for(char ch:str)
    {
        if(isdigit(ch))
            temp+=ch;
        else
        {
            sum+=atoi(temp.c_str());
            temp = "";
        }
    }
    return sum + atoi(temp.c_str());
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout<<sum(str)<<endl;
	}
	return 0;
}
