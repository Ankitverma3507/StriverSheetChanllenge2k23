#include <bits/stdc++.h>
using namespace std;
 
class MedianFinder {

    private:
     priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty()) {
            lower.push(num);
            return;
        }

        if (num > lower.top()) higher.push(num);
        else lower.push(num);

        if (lower.size() > higher.size()) {
            higher.push(lower.top());
            lower.pop();
        } else if (lower.size() < higher.size()) {
            lower.push(higher.top());
            higher.pop();
        }
    }
    
    double findMedian() {
        if (lower.size() == higher.size())
            return (lower.top() + higher.top()) / 2.0;

        return lower.size() > higher.size() ? lower.top() : higher.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */