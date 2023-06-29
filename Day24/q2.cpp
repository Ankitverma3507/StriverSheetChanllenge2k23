#include<bits/stdc++.h>
using namespace std;
//using pq
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(V,1e9);
        dis[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dist= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjnode= it[0];
                int edgewt= it[1];
                
                if(dist+ edgewt < dis[adjnode])
                {
                    dis[adjnode]= dist+edgewt;
                    pq.push({dist+edgewt, adjnode});
                }
            }
        }
        return dis;
        
    }
};






//using set ds
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       set<pair<int,int>>st;
        vector<int>dis(V,1e9);
        dis[S]=0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto top= *(st.begin());
            int dist= top.first;
            int node= top.second;
            st.erase(top);
            
            for(auto it: adj[node]){
                int adjnode= it[0];
                int edgewt= it[1];
                
                if(dist+ edgewt < dis[adjnode])
                {
                    if(dis[adjnode] != 1e9)
                    {
                        st.erase({dis[adjnode],adjnode});
                    }
                    
                    dis[adjnode]= dist+edgewt;
                    st.insert({dist+edgewt, adjnode});
                }
            }
        }
        return dis;
        
    }
};

