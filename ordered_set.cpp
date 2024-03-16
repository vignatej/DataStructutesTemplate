#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// look at both orderedset and multiordered set


int main() {
    ordered_set <int> a;
    a.insert(2);
    a.insert(4);
    a.insert(3);
    a.insert(7);
    a.insert(5);

    // Here, find_by_order(x) will return the 
    // address of (x+1)th element in the ordered_set a

    cout << *a.find_by_order(3) << endl; //output is 5

    // Here, order_of_key(x) will return the 
    // number of elements strictly less than x.
    cout << (a.order_of_key(10)) << endl; //output is 5
    a.erase(7);
    cout << (a.order_of_key(10)) << endl; //output is 5
    cout<<"----------------------------------\n";

    multi_ordered_set<int> b;
    b.insert(1);
    b.insert(10);
    b.insert(10);
    b.insert(10);
    b.insert(10);
    b.insert(7);
    b.insert(5);
    cout << *b.find_by_order(2) << endl; //output is 7
    cout << *b.find_by_order(5) << endl; //output is 10
    cout << (b.order_of_key(10)) << endl; //output is 3
    cout << (b.order_of_key(11)) << endl; //output is 7



}