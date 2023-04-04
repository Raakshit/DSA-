//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int solve(string str , char a){
    int count = 0;
    for(int i =0;i<str.length();i++){
        if(str[i] != a) continue;
        while(str[i] == a){
            i++;
        }
        count++;
    }
    return count+1;
}

int minSteps(string str) {
    int remove_a = solve(str,'a');
    int remove_b = solve(str,'b');
    
    return min(remove_a , remove_b);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends