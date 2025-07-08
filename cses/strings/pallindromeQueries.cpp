#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define VVI vector<vector<int>>
#define VI vector<int>
#define PB push_back
const int P = 31;
const int M = 1e9 + 9;

// Modular inverse using Fermat's little theorem
int modinv(int a, int mod) {
    int res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

template <typename T>
class segment_tree {
   public:
    segment_tree(vector<T> a) {
        n = a.size();
        tree = vector<tree_node>(4 * n);
        build(0, 0, n, a);
    }
    void add_range(size_t l, size_t r, T val) {
        add_range_main(0, 0, n, l, r, val);
    }
    T query(size_t l, size_t r) {
        return query_main(0, 0, n, l, r);
    }

   private:
    struct tree_node {
        T value = 0;
        T inc = 0;
    };
    vector<tree_node> tree;
    size_t n;

    void build(size_t node, size_t l, size_t r, vector<T> &a) {
        if (r - l == 1) {
            tree[node].value = a[l];
            return;
        }
        size_t mid = (l + r) / 2;
        build(node * 2 + 1, l, mid, a);
        build(node * 2 + 2, mid, r, a);
        tree[node].value = (tree[node * 2 + 1].value + tree[node * 2 + 2].value) % M;
    }

    void push(size_t node, size_t l, size_t r) {
        if (tree[node].inc) {
            size_t mid = (l + r) / 2;
            add_range_main(node * 2 + 1, l, mid, l, mid, tree[node].inc);
            add_range_main(node * 2 + 2, mid, r, mid, r, tree[node].inc);
            tree[node].inc = 0;
        }
    }

    void add_range_main(size_t node, size_t l, size_t r, size_t tree_l, size_t tree_r, T val) {
        if (tree_r <= l || r <= tree_l) return;
        if (tree_l <= l && r <= tree_r) {
            tree[node].value = (tree[node].value + (r - l) * val % M) % M;
            tree[node].inc = (tree[node].inc + val) % M;
            return;
        }
        push(node, l, r);
        size_t mid = (l + r) / 2;
        add_range_main(node * 2 + 1, l, mid, tree_l, tree_r, val);
        add_range_main(node * 2 + 2, mid, r, tree_l, tree_r, val);
        tree[node].value = (tree[node * 2 + 1].value + tree[node * 2 + 2].value) % M;
    }

    T query_main(size_t node, size_t l, size_t r, size_t tree_l, size_t tree_r) {
        if (tree_r <= l || r <= tree_l) return 0;
        if (tree_l <= l && r <= tree_r) return tree[node].value;
        push(node, l, r);
        size_t mid = (l + r) / 2;
        return (query_main(node * 2 + 1, l, mid, tree_l, tree_r) +
                query_main(node * 2 + 2, mid, r, tree_l, tree_r)) % M;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    string rs = s;
    reverse(rs.begin(), rs.end());

    VI ppow(n + 1, 1), inv_p(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        ppow[i] = (ppow[i - 1] * P) % M;
        inv_p[i] = modinv(ppow[i], M);
    }

    VI fh(n, 0), bh(n, 0);
    for (int i = 0; i < n; ++i) {
        fh[i] = ((s[i] - 'a' + 1) * ppow[i]) % M;
        bh[i] = ((rs[i] - 'a' + 1) * ppow[i]) % M;
    }

    segment_tree<int> fst(fh), bst(bh);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char x;
            cin >> pos >> x;
            pos--;
            int old_val = (s[pos] - 'a' + 1) * ppow[pos] % M;
            int new_val = (x - 'a' + 1) * ppow[pos] % M;
            int inc = (new_val - old_val + M) % M;
            fst.add_range(pos, pos + 1, inc);

            int rpos = n - pos - 1;
            old_val = (rs[rpos] - 'a' + 1) * ppow[rpos] % M;
            new_val = (x - 'a' + 1) * ppow[rpos] % M;
            inc = (new_val - old_val + M) % M;
            bst.add_range(rpos, rpos + 1, inc);

            s[pos] = x;
            rs[rpos] = x;
        } else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            int h1 = fst.query(a, b + 1);
            h1 = h1 * inv_p[a] % M;

            int ra = n - b - 1;
            int rb = n - a - 1;
            int h2 = bst.query(ra, rb + 1);
            h2 = h2 * inv_p[ra] % M;

            if (h1 == h2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
