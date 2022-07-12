//Author : Siddharth Saurav (Chem 23)

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

//Kruskal's MST

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

    if(p1 == p2 and p1 != -1) return;

    if(size[p1] > size[p2]){
        par[p2] = p1;
        size[p1] += size[p2];
    }
    else{
        par[p1] = p2;
        size[p2] += size[p1];
    }
}


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
    vector<pair<int, pair<int, int>>> edge;
    for(int i = 1; i<=n; i++){
        for(auto x : g[i]){
            edge.push_back({x.ss, {max(i, x.ff), min(i, x.ff)}});
        }
    }
    sort(edge.begin(), edge.end());
    int wt = 0;
    for(auto x : edge){
        if(_find(x.ss.ff) == -1 or (_find(x.ss.ff)) != _find(x.ss.ss)){
            wt += x.ff;
            _union(x.ss.ff, x.ss.ss);
        }
    }
    cout << wt << endl;
}    





//Prim's MST



nline
Most interesting courses in one place
SHARE
TWEET
sidd_11
Untitled
SIDD_11
JUN 13TH, 2022
11
NEVER
 1.15 KB
       
PRIMS MST-------------------------------------------------------------------
 
 // 1. Make a minHeap, a visited map, initialise minHeap with any of the node;
 // 2. While minheap is not empty -> take out top node, pop it
 // 3. check if it is visited, if so ignore otherwise add to cost
 // 4. iterate to all adjacent node of that top node if not visited add to heap.
 // 5. return cost.
 // 6. Based on greedy, uses adjacency list implementation for efficient functioning.
 
int primsMST(){
    set<pair<int, int>> s;
    s.insert({0, 1});
    vector<bool> vis(n+1, false);
    int cnt_nodes = 0;
    int min_cost = 0;
    while(!pq.empty()){
        auto nodePair = *(s.begin()); // first -> dist, second -> vertex
        s.erase(nodePair);
        if(vis[nodePair.second] == true){
            continue;
        }
        cnt_nodes++;
        min_cost += nodePair.first;
        vis[nodePair.second] = true;
        for(auto x : adj[nodePair.second]){
            if(vis[x.first] == false){
                s.insert({x.second, x.first});
            }
        }
    }
    if(cnt_nodes != n){
        cout << "No MST found" << endl;
        return;
    }
    return min_cost;
}