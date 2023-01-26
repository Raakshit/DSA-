//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char>upper;
        vector<char>lower;
        
        for(int i =0;i<n;i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                lower.push_back(str[i]);
                str[i] = '0';
            }else {
                upper.push_back(str[i]);
                str[i] = '1';
            }
        }
        
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        
        int low = 0;
        int up = 0;
        
        for(int i =0 ;i<n;i++){
            if(str[i] == '0'){
                str[i] = lower[low++];
            }else {
                str[i] = upper[up++];
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends