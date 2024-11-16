/*
Here each node of the tree will contain vector of numbers falling inside
that node in sorted order.
TC : Build - O(nlogn), Query - O(logn*logn)
Space Complexity -> O(n*log(n))
(total number of elements in each level of seg tree * number of levels)

Number of element greater than x is implemented in following code.
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> seg;

void build(vector<int>&nums, int node, int l, int r) {
    if(l == r){
        seg[node] = {nums[l]};
        return;
    }

    int mid = (l+r)/2;

    build(nums, 2*node, l, mid);
    build(nums, 2*node + 1, mid+1, r);

    std::merge(seg[2*node].begin(), seg[2*node].end(), 
               seg[2*node+1].begin(), seg[2*node+1].end(), 
               back_inserter(seg[node]));
}

int query(int val, int i, int j, int node, int l, int r) {
    if(l>=i and r<=j) {
        return seg[node].size() - (upper_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin());
    }
    if(l>j || r<i) {
        return 0;
    }
    int mid = (l+r)/2;
    int a1 = query(val, i, j, 2*node, l, mid);
    int a2 = query(val, i, j, 2*node+1, mid+1, r);

    return a1 + a2;
}

int main() {
    vector<int> num = {1,4,2,7,4,9,4,2};
    n = num.size();
    seg.resize(4*n, vector<int>());
    build(num, 1, 0, n-1);

    int val, l, r;
    cin >> val >> l >> r;
    cout << query(val, l, r, 1, 0, n-1);
}
