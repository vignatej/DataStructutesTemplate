#include <bits/stdc++.h>
using namespace std;

struct LazySegTreeSum {
    int n;
    vector<long long> tree, lazy;

    LazySegTreeSum(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<long long>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            tree[idx] += (r - l + 1) * lazy[idx];
            if (l != r) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, long long val) {
        push(idx, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(idx * 2, l, mid, ql, qr) +
               query(idx * 2 + 1, mid + 1, r, ql, qr);
    }
};

struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int sz) {
        n = sz;
        tree.assign(4 * n, LLONG_MAX);
        lazy.assign(4 * n, 0);
    }

    void build(vector<long long>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            tree[idx] += lazy[idx];
            if (l != r) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, long long val) {
        push(idx, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);
        if (qr < l || ql > r) return LLONG_MAX;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return min(query(idx * 2, l, mid, ql, qr),
                   query(idx * 2 + 1, mid + 1, r, ql, qr));
    }
};

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     cin >> n >> q;
//     vector<long long> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     LazySegTree seg(n);
//     seg.build(arr, 1, 0, n - 1);

//     while (q--) {
//         int type;
//         cin >> type;
//         if (type == 1) {
//             int l, r;
//             long long val;
//             cin >> l >> r >> val;
//             seg.update(1, 0, n - 1, l, r, val);
//         } else if (type == 2) {
//             int l, r;
//             cin >> l >> r;
//             cout << seg.query(1, 0, n - 1, l, r) << "\n";
//         }
//     }
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     cin >> n >> q;
//     vector<long long> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     LazySegTree seg(n);
//     seg.build(arr, 1, 0, n - 1);

//     while (q--) {
//         int type;
//         cin >> type;
//         if (type == 1) {
//             int l, r;
//             long long val;
//             cin >> l >> r >> val;
//             seg.update(1, 0, n - 1, l, r, val);
//         } else if (type == 2) {
//             int l, r;
//             cin >> l >> r;
//             cout << seg.query(1, 0, n - 1, l, r) << "\n";
//         }
//     }
// }
