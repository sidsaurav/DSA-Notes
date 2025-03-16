//Author : Siddharth Saurav (IIT BHU'23)

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

/*
Dijkstra's Algorithm
    Step 1: In bfs we start with queue here we will start with p-queue or set and dist array initiated with a large value.
    Step 2: Push {dist, node} in set for src node.
    Step 3: Pick top node. Pop it. Check for its nbr if its distance through that node is less than dist[that_node].
            If yes update dist[that_node] and insert new pair in the set.
    Step 4: Repeat this till set is not empty.

Dijkstra does not work for negative weight cycle int the graph.
*/

/*
Optimisation: jis jis node k lye dist fix kr lye use vis array me true kr do and jb v wo encounter ho while loop me to
continue kr do else vis[node] = 1. This will avoid TLE in some cases.
*/

vector<vector<pii>> g(1e6);
vector<int> dist(1e6, 1e9);
vector<int> vis(1e6, 1e9); // optimisation
vector<int> par(1e6, -1);

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].pb({b, wt});
        g[b].pb({a, wt});
    }
    multiset<pair<int, int>> s; // {dist, {node, path}}.
    s.insert({0, 2});
    dist[2] = 0;
    while(!s.empty()){
        auto fr = *s.begin();
        s.erase(s.begin());
        
        //optimisation
        if(vis[fr.ss] == 1) continue;
        vis[fr.ss] = 1;
        
        for(auto x : g[fr.ss]){
            // never use dist[fr.ss], instead use fr.ff
            if(dist[x.ff] > fr.ff+x.ss){
                dist[x.ff] = fr.ff+x.ss;
                par[x.ff] = fr.ss;
                s.insert({dist[x.ff], x.ff});
            }
        }
    }
    cout << dist[4] << endl;
    cout << path[3] << endl;
}

// TC: ELogV - https://www.youtube.com/watch?v=3dINsjyfooY

/*

Time Complexity -

Vertex Operations: O(V log V)
Extracting the minimum vertex from the priority queue (binary heap) happens V times (once per vertex).

Each extraction takes O(log V) time due to heap operations.

Total: V × O(log V) = O(V log V).

Edge Operations: O(E log V)

For each extracted vertex, all its E edges are relaxed (examined).

If a shorter path is found, the distance is updated, and the new key is inserted into the heap (or decreased if supported).

In a standard binary heap, decrease-key is not directly supported, so a new entry is added instead (leading to duplicates in the heap). This still takes O(log V) time per insertion.

Even with duplicates, each edge can trigger at most one heap operation (insertion or decrease-key).

Total: E × O(log V) = O(E log V).

Combined Complexity: O((V + E) log V)
Dominant term: Since E ≥ V in most graphs (e.g., connected graphs), the complexity is often simplified to O(E log V). However, strictly speaking, it is O((V + E) log V).

Key Nuance: Binary Heap Limitations
A binary heap does not natively support O(1) decrease-key (unlike Fibonacci heaps). Instead, duplicates are inserted, but the total number of heap operations remains bounded by O(E + V), preserving the O((V + E) log V) complexity.

*/
