#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////_________->>>>>>>>>>>>>>>> optimal


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    
    
    bool isSafe(int node,int color[], int n, int col, bool graph[101][101] ){
        for(int k=0; k<n;k++){
            if(k != node and graph[k][node]==1 and color[k] ==col)//this graph[k][node] is checkin that is that node is adj node or not
            return false;
        }
        return true;
    }
    bool isColor(int node, int color[], int m, int n, bool graph[101][101]){
        if(node==n) return true;
        
        for(int i=1; i<=m; i++){
            if(isSafe(node, color,n,i,graph)){
                color[node]=i;
                if(isColor(node+1, color,m,n,graph)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]= {0};
        if(isColor(0,color,m,n,graph)) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends