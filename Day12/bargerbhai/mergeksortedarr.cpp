#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
    int data;
    int i;
    int j;

    node(int data, int row , int col){
        this->data=data;
        i= row; j=col;
    }
};
class compare{
    public:
    bool operator()(node *a, node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<node*, vector<node*>, compare>pq;
    for(int i=0 ; i<k; i++){
        node* temp= new node(arr[i][0], i,0);
        pq.push(temp);
    }


    while(pq.size()>0){
        node* top= pq.top();
        pq.pop();
        ans.push_back(top->data);

        int i= top->i;
        int j= top->j;
        if(j+1 < arr[i].size()){
            node* temp= new node(arr[i][j+1], i, j+1);
            pq.push(temp);
        }

    }
    return ans;
}
