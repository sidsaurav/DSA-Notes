#include <bits/stdc++.h>
using namespace std;


vvi g;
vi vis;
int n, e;

void dfs(int node, string str, int cnt){
    //
    if(cnt == n){
        cout << str;
        bool find = false;
        for(auto x : g[node]){
            if(x == 0)
            find = true;
        }
        if(find) cout << "*";
        else cout << ".";
        cout << endl;
        return;
    }

    //
    vis[node] = 1;
    for(auto x : g[node]){
        if(!vis[x]){
            dfs(x, str + to_string(x), cnt+1);
        }
    }
    vis[node] = 0;
}

void solve(int case_num){
    cin >> n >> e;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i = 0; i<e; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, "0", 1);
}

int32_t main(){
    fastio();
    int t = 1;
    //cin >> t;
    rep(i, 1, t+1)
    solve(i);
}    