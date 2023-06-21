#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////----------->>>>>>>better app
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int> pq;
	vector<int>finalans;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int sum=a[i]+b[j]; 
			pq.push(sum);
		}
	}


	
	for(int i=1; i<=k; i++){
		int pqans= pq.top();
		finalans.push_back(pqans);
		pq.pop();
	}
	return finalans;
}













#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////otimised approach
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    // Write your code here.

    priority_queue<pair<int, pair<int, int>>> pq;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    set<pair<int, int>> s;
    vector<int> ans;

    pq.push({a[0] + b[0], {0, 0}});

    for (int i = 0; i < k; i++)
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        ans.push_back(p.first);

        if (p.second.first + 1 < n and s.find({p.second.first + 1, p.second.second}) == s.end())
        {
            s.insert({(p.second.first) + 1, p.second.second});
            pq.push({a[p.second.first + 1] + b[p.second.second], {p.second.first + 1, p.second.second}});
        }

        if (p.second.second + 1 < n and s.find({p.second.first, p.second.second + 1}) == s.end())
            {s.insert({p.second.first, (p.second.second) + 1});
                pq.push({a[p.second.first] + b[p.second.second + 1], {p.second.first, p.second.second + 1}});}
            
    }

    return ans;
}