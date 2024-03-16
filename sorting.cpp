#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
#include <limits>
#include <utility>
#include <cmath>
#include <list>
#include <sstream>
#include <set>
#include <numeric>
using namespace std;


void mergesort(vector<int> &nums,int left, int right){
    // int l = nums.size();
    if(left + 1 == right || left >= right) return;
    int m = (left + right)/2;
    mergesort(nums, left,m);
    mergesort(nums, m, right);
    int i{left}, j{m};
    vector<int> new_v;
    new_v.reserve(right-left);
    
    while(i<=m && j<right){
        if(nums[i]<=nums[j]){
            new_v.push_back(nums[i]);
            i++;
        }else{
            new_v.push_back(nums[j]);
            j++;
        }
    }
    while(i<=m){
        new_v.push_back(nums[i]);
        i++;
    }
    while(j<right){
        new_v.push_back(nums[j]);
        j++;
    }
    copy(new_v.begin(), new_v.end(), nums.begin()+left);
}


void bubblesort(int * a, int n){
    bool swap = false;
    do{
        swap=false;
        for(int i = 0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int t = a[i+1];
                a[i+1]=a[i];
                a[i]=t;
                swap=true;
                break;
            }
        }
    }while(swap==true);
}

void selectionsort(int* a, int n){
    for(int i = 0;i<n;i++){
        int m = i;
        for(int j = i;j<n;j++){
            if(a[j]<a[m]){
                m=j;
            }
        }
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void inserionsort(int* a, int n){
    for(int i=1;i<n;i++){
        if(a[i-1]<=a[i]) continue;
        int tmp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>tmp){ 
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}

void mergesort(int *a, int l, int r){
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    int *n = new int[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] < a[j]) {
            n[k] = a[i];
            k++; i++;
        } else {
            n[k] = a[j];
            j++; k++;
        }
    }
    while (i <= m) {
        n[k] = a[i];
        k++; i++;
    }
    while (j <= r) {
        n[k] = a[j];
        k++; j++;
    }
    
    for (int q = l, w = 0; q <= r; q++, w++) {
        a[q] = n[w];
    }

    delete[] n;
}



void quicksort(int a[], int l, int r){
    if(l>=r) return;
    int p = a[r];
    int i=l-1;
    int j = l;
    while(j<r){
        if(a[j]<=p){
            i++;
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
        j++;
    }
    i++;
    int t = a[r];
    a[r] = a[i];
    a[i] = t;
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}


int* countsort(int a[], int m, int n){
    int *c = new int[m+1];
    for(int i=0;i<=m;i++) c[i] = 0;
    for(int i = 0;i<n;i++){
        c[a[i]] +=1;
    }
    for(int i = 1;i<=m;i++){
        c[i] += c[i-1];
    }
    int* o = new int[n];
    for(int i=0;i<n;i++){
        c[a[i]] -=1;
        o[c[a[i]]] = a[i];
    }
    for(int i = 0;i<n;i++) cout<<o[i]<<",";
    return o;
}


vector<double> bucketsort(vector<double> a, int n, int k){
    vector<double> b[k];
    double ma = numeric_limits<double>::min();
    double mi = numeric_limits<double>::max();
    for(int i = 0;i<n;i++){
        if (a[i]>ma) ma=a[i];
        if(a[i]<mi) mi=a[i];
    };
    double ran_ge = (ma-mi)/k;
    for(int i = 0;i<n;i++){
        cout<<(a[i]-mi)/ran_ge<<endl;
        int b_i = (floor) (a[i]-mi)/ran_ge;
        if(b_i>=k) b_i = k-1;
        b[b_i].push_back(a[i]);
    }
    for(int i=0;i<k;i++){
        sort(b[i].begin(), b[i].end());
    }
    vector<double> ans;
    for(int i= 0;i<k;i++){
        copy(b[i].begin(), b[i].end(), back_inserter(ans));
    }
    return ans;
}

int keyy(int a, int n){
    string b = to_string(a);
    int l = b.length();
    if(n>l) return 0;
    reverse(b.begin(), b.end());
    return (int)b[n-1] -(int)'0';
}



void radixsort(vector<int>& a){
    int n = a.size();
    int m = numeric_limits<int>::min();
    for(int i = 0;i<n;i++){
        m = max(m, a[i]);
    }
    int max_size = to_string(m).length();
    int i = 1;
    while(i<=max_size){
        sort(a.begin(), a.end(),[i](int x, int y){return keyy(x, i)<keyy(y, i);});
        i++;
    }
    
}





int main2()
{
    int a[] = {1,6,5,1,2,6,9,2,100};
    for(int i = 0;i<10;i++) cout<<a[i]<<", ";
    cout<<endl;
    cout<<"-----start------"<<endl;
    // countsort(a, 100, 9);
    
    vector<double> v {1.32,6.23,85.3,20.2,0.6,200,123,-1,-600};
    for(auto i:v) cout<<i<<", ";cout<<endl;
    vector<double> ans  = bucketsort(v, v.size(), 3);
    for(auto i:ans) cout<<i<<", ";cout<<endl;
    
    cout<<endl;
    cout<<"-----end------"<<endl;
    for(int i = 0;i<10;i++) cout<<a[i]<<", ";
};
int main(int argc, char const *argv[])
{
    vector<int> v {1,5000,203,659,1203,22,6,512,18,30,22,60,200,0};
    radixsort(v);
    for(auto i:v) cout<<i<<", ";

}
