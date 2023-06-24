//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool isEqual(string s , string t){
        for(int i=0;i<t.size();i++){
            if(s[i] != t[i]) return false;
        }
        return true;
    }

    int klengthpref(string arr[], int n, int k, string str){    
        int count=0;
        string match = "";
        int m = str.size();
        if(k>m) return 0;
        
        for(int i =0;i<k;i++){
            match += str[i];
        }
        
        for(int i =0;i<n;i++){
            if(arr[i].size() >= k && isEqual(arr[i] , match))count++;
        }
        
        return count;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends