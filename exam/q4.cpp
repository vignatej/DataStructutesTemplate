#include <bits/stdc++.h>
using namespace std;

class RideSharingSystem {
public:
    deque<int> d;
    // set<int> c;
    set<pair<int, int>> r; int rc{0};
    map<int, int> ufr;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        
        ufr[riderId]=++rc;
        r.insert({rc, riderId});
    }
    
    void addDriver(int driverId) {
        d.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(r.size()==0 || d.size()==0) return {-1, -1}; 
        auto tr = *r.begin(); r.erase(tr);
        ufr.erase(tr.first);
        vector<int> ans = {d.front(), tr.second};
        d.pop_front();
        return ans;
    }
    
    void cancelRider(int riderId) {
        if(ufr.find(riderId)==ufr.end()) return;
        int f = ufr[riderId];
        r.erase({f, riderId});
        ufr.erase(riderId);
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */


signed main(){
    RideSharingSystem s;
    s.addRider(8);
    s.addDriver(8);
    s.addDriver(6);
    auto fa = s.matchDriverWithRider();
    cout<<fa[0]<<' '<<fa[1]<<'\n';
    s.addRider(2);
    s.cancelRider(2);
    fa = s.matchDriverWithRider();
    cout<<fa[0]<<' '<<fa[1]<<'\n';
    

    return 0;
}