// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {
// 	public:
// 	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         // code here
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
//         vector<int>vis(V,0);
//         pq.push({0,0});// format of storing element in pq is {wt,node}
//         int sum=0;
//         while(!pq.empty()){
//             auto it= pq.top();
//             int wt= it.first;
//             int node= it.second;
//             pq.pop();
            
//             if(vis[node]==1) continue; //this is means this node is already added into mst
//             vis[node]=1;
//             sum+= wt;
            
//             for(auto it: adj[node]){
//                 int adjnode= it[0];
//                 int edgwt= it[1];
//                 if(!vis[adjnode])
//                 {
//                     pq.push({edgwt, adjnode});
//                 }
//             }
            
//         }
//         return sum;
//     }
// };





//when we want to print mst instead of getting summation of mst
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<pair<int,int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>>pq;
        vector<int>vis(V,0);
        vector<pair<int,int>>mst;
        pq.push({0,{0,-1}});// format of storing element in pq is {wt,node}
        int sum=0;
        while(!pq.empty()){
            auto it= pq.top();
            int wt= it.first;
            int node= it.second.first;
            int parent= it.second.second;
            pq.pop();
            
            if(vis[node]==1) continue; //this is means this node is already added into mst
            vis[node]=1;
            mst.push_back({node,parent});
            sum+= wt;
            
            for(auto it: adj[node]){
                int adjnode= it[0];
                int edgwt= it[1];
                if(!vis[adjnode])
                {
                    pq.push({edgwt, {adjnode, node}});
                }
            }
            
        }
        return mst;
    }
};
