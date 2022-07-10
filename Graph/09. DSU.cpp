//Author: Siddharth Saurav
//cf @ sidd_11

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

vector<vector<pii>> g;

// Optimised Implementation

vector<int> par(100, -1);
vector<int> size(100, 1); // rank compression using size

int _find(int x){
    if(par[x] == -1) return x;
    return par[x] = _find(par[x]); // path compression
}

void _union(int x, int y){
    int p1 = _find(x);
    int p2 = _find(y);

    if(p1 == p2) return;

    if(size[p1] > size[p2]){
        par[p2] = p1;
        size[p1] += size[p2];
    }
    else{
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

// TC after optimisation : almost O(1)

int32_t main(){
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i<m; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
        g[b].push_back({a, wt});
    }
}    