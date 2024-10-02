#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9+7;
const int N = 1e5+1;
vector<int> fact(N + 1, 1);

int binaryexponential(int no, int power) {
    int ans = 1;
    while (power) {
        if (power & 1) {
            ans = (ans * no) % M;
        }
        no = (no * no) % M;
        power >>= 1;
    }
    return ans;
}

int ncr(int n, int r) {
    if (r < 0 || n < 0 || n < r) return 0;
    int value = (fact[r] * fact[n - r]) % M;
    int ans = (fact[n] * binaryexponential(value, M - 2)) % M;
    return ans;
}

int32_t main() {
    int t;
    cin >> t;
    for (int i = 1; i <= N; ++i) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pre[i + 1] = pre[i] + a[i];
        }
        int half_length = (k / 2);
        int ans = 0;
        int count_zeros = n - pre[n];
        int count_ones = pre[n];

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                continue;
            } else {
                int pre_no = count_zeros + pre[i];
                int post_ones = pre[n] - pre[i + 1];
                //cout << (i + 1) << " " << pre_no << " " << post_ones << endl;
                int value = (ncr(pre_no, half_length) * ncr(post_ones, half_length)) % M;
                ans = (ans + value) % M;
            }
            // cout << ans << endl;
        }
        cout << (ans ) << endl;  // This division by 2 might need adjustment based on the problem's requirements.
    }

    return 0;
}