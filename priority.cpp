#include <bits/stdc++.h>

using namespace std;
int main(){
    auto cmp = [](pair<int, int> &p1, pair<int, int> &p2){return p1<p2;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pair<int, int> a{1, 2};
    pq.push(a);
    pq.push({2, 3});
    pq.push({2, 4});
    pq.push({5, 3});
    while(pq.size()){cout<<pq.top().first<<"--"<<pq.top().second<<endl;pq.pop();}
}