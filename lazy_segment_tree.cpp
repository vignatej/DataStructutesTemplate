#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

/**
 * @brief A data structure that allow update point/range and query operations efficently
 *
 */
template <typename T>
class segment_tree {
   public:
    /**
     * @brief Initialize a new segment tree object
     *
     * @param a An array of value
     */
    segment_tree(vector<T> a) {
        n = a.size();
        tree = vector<tree_node>(4 * n);
        build(0, 0, n, a);
    }
    /**
     * @brief Increase all item in range [l, r) by val
     *
     * @param l Left index
     * @param r Right index
     * @param val Value to increase by
     */
    void add_range(size_t l, size_t r, T val) {
        add_range_main(0, 0, n, l, r, val);
    }
    /**
     * @brief Get sum of range [l, r)
     *
     * @param l Left index
     * @param r Right index
     * @return The sum of range [l, r)
     */
    T query(size_t l, size_t r) {
        return query_main(0, 0, n, l, r);
    }

   private:
    struct tree_node {
        T value;
        T inc;
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
        tree[node].value = tree[node * 2 + 1].value + tree[node * 2 + 2].value;
    }
    void push(size_t node, size_t l, size_t r) {
        size_t mid = (l + r) / 2;
        if (tree[node].inc) {
            add_range_main(node * 2 + 1, l, mid, l, mid, tree[node].inc);
            add_range_main(node * 2 + 2, mid, r, mid, r, tree[node].inc);
            tree[node].inc = 0;
        }
    }
    void add_range_main(size_t node, size_t l, size_t r, size_t tree_l, size_t tree_r, T val) {
        if (tree_r <= l || r <= tree_l) return;
        if (tree_l <= l && r <= tree_r) {
            tree[node].value += (r - l) * val;
            tree[node].inc += val;
            return;
        }
        push(node, l, r);
        size_t mid = (l + r) / 2;
        add_range_main(node * 2 + 1, l, mid, tree_l, tree_r, val);
        add_range_main(node * 2 + 2, mid, r, tree_l, tree_r, val);
        tree[node].value = tree[node * 2 + 1].value + tree[node * 2 + 2].value;
    }
    T query_main(size_t node, size_t l, size_t r, size_t tree_l, size_t tree_r) {
        if (tree_r <= l || r <= tree_l) return 0;
        if (tree_l <= l && r <= tree_r) return tree[node].value;
        push(node, l, r);
        size_t mid = (l + r) / 2;
        return query_main(node * 2 + 1, l, mid, tree_l, tree_r) + query_main(node * 2 + 2, mid, r, tree_l, tree_r);
    }
};

int main() {
    vector<LL> a = {1, 2, 3, 4};
    segment_tree<LL> tree(a);          // initialize segment tree
    cout << tree.query(0, 4) << '\n';  // 10
    tree.add_range(0, 4, 1);           // increase all items in range [l, r) by 1
    cout << tree.query(0, 4) << '\n';  // 14
}