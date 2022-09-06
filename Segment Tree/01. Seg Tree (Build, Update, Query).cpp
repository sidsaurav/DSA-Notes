#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> seg;

void build_sum(int node, int l, int r){
    if(l == r){
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build_sum(2*node, l, mid);
    build_sum(2*node + 1, mid+1, r);

    //this is logical line
    seg[node] = seg[2*node] + seg[2*node + 1];
}

int query_sum( int i, int j, int node, int l, int r){
    if(r < i or l > j) return 0; // Depends on questions
    if(l >= i and r <= j) return seg[node];

    int mid = (l+r)/2;
    
    int sub1 = query_sum(i, j, 2*node, l, mid );
    int sub2 = query_sum(i, j, 2*node+1, mid+1, r);

    return sub1+sub2;
}



//--------------------------------------------------------------------------------




void build_max(int node, int l, int r){
    if(l == r){
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build_max(2*node, l, mid);
    build_max(2*node + 1, mid+1, r);

    //this is logical line
    seg[node] = max(seg[2*node],seg[2*node + 1]);
}

int query_max( int i, int j, int node, int l, int r){
    if(r < i or l > j) return -1e9; // Depends on questions
    if(l >= i and r <= j) return seg[node];

    int mid = (l+r)/2;
    
    int sub1 = query_max(i, j, 2*node, l, mid);
    int sub2 = query_max(i, j, 2*node+1, mid+1, r);

    return max(sub1, sub2);
}

void update_max(int idx, int val, int node, int l, int r){
    if(l == r){
        v[l] = val;
        seg[node] = val;
        return;
    }

    int mid = (l + r)/2;
    if(idx<=mid) update_max(idx, val, 2*node, l, mid);
    else update_max(idx, val, 2*node+1, mid+1, r);

    seg[node] = max(seg[2*node], seg[2*node+1]);
}


int main(){
    int n;
    cin >> n;
    v.resize(n);
    seg.resize(4*n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    build_max(1, 0, n-1);
    update_max(2, 15, 1, 0, n-1); // update index 2 with val 15.
    cout << query_max(1, 5, 1, 0, n-1); // query from 1 to 4.
}    