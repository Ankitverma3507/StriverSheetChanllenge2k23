

#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////optimised app
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() !=1){
            int a= st.top();
            st.pop();
            int b= st.top();
            st.pop();
            
            if(M[a][b] ==1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        ///////now turn to verify potential candidate
        //rowcheck
        int candidate= st.top();
        int zerocnt=0;
        bool rowcheck=false;
        for(int i=0; i<n; i++){
            if(M[candidate][i]==0)
            zerocnt++;
        }
        
        if(zerocnt==n) rowcheck=true;
        
        
        // colcheck
        bool colcheck=false;
        int onecnt=0;
        for(int i=0; i<n; i++){
            if(M[i][candidate]==1)
            onecnt++;
        }
        
        if(onecnt==n-1) colcheck=true;
        
        if(rowcheck and colcheck){
            return candidate;
        }
        else return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends