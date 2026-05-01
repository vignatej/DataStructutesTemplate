#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    int range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

vector<int> get_first(vector<int> arr){
    int n = arr.size();

    // Coordinate compression
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    Fenwick bit_sum(temp.size());
    Fenwick bit_count(temp.size());

    int total_sum = 0;
    int total_count = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;

        int sum_less = bit_sum.query(idx - 1);
        int count_less = bit_count.query(idx - 1);

        int sum_ge = total_sum - sum_less;
        int count_ge = total_count - count_less;

        // cout << "Index " << i 
        //      << " -> Sum: " << sum_ge 
        //      << ", Count: " << count_ge << "\n";

        ans.push_back(sum_ge - count_ge*(arr[i]-1));

        bit_sum.update(idx, arr[i]);
        bit_count.update(idx, 1);

        total_sum += arr[i];
        total_count += 1;
    }
    return ans;
}

int c_sum(int n){
    return (n*(n+1))>>1;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n); for(auto &i: v) cin>>i;
        vector<int> disp = get_first(v);
        int mdn = *max_element(disp.begin(), disp.end());
        int mdp = 0; for(int i = 0;i<n;i++) if(disp[i]==mdn) mdp=i;
        v[mdp]--;

        map<int, vector<int>> rm;
        for(int i = 0;i<n;i++) rm[v[i]].push_back(i);
        set<int> cs;
        int sum{0}, ans{0};
        for(auto it = rm.rbegin();it!=rm.rend();it++){
            int cv = it->first;
            vector<int> posns = it->second;
            for(auto i: posns) cs.insert(i);
            for(auto i: posns) sum+=i+1;
            int cans = c_sum(n)-c_sum(n-cs.size());
            cans-=sum;
            int ch = (next(it)!=rm.rend() ? (cv - next(it)->first): cv);
            ans+=cans*(ch);
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}