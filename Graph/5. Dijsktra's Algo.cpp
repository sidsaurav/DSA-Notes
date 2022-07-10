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

vector<vector<pii>> g(1e6);
vector<int> dist(1e6, 1e9);
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
    path[2] = "2->";
    while(!s.empty()){
        auto p = *s.begin();
        s.erase(s.begin());
        for(auto x : g[p.ss]){
            if(dist[x.ff] > dist[p.ss]+x.ss){
                dist[x.ff] = dist[p.ss]+x.ss;
                // path[x.ff] = path[p.ss] + to_string(x.ff) + "->"; // updating path
                par[x.ff] = p.ss;
                s.insert({dist[x.ff], x.ff});
            }
        }
    }
    cout << dist[4] << endl;
    cout << path[3] << endl;
}
