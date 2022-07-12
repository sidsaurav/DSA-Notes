//Author : Siddharth Saurav (Chem 23)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
#define nINF -1e18
#define MOD 1000000007
#define PI 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define nl "\n"
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define all(v) v.begin(), v.end()
#define lb(v, x) (lower_bound(all(v), (x)) - v.begin())
#define ub(v, x) (upper_bound(all(v), (x)) - v.begin())
#define find(v, x) (find(all(v), (x)) - v.begin())
#define read(vect) for(auto &x : vect) cin >> x
#define print(vect) for(auto &x : vect) cout << x << " "
#define google(ans) cout << "Case #" << case_num << ": " << ans << nl;
#define deb(x) cout << "deb " << #x << " : "; _print(x); cout << nl
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//-----------------------------------------------------------------------------------------------------------------------------------------------

template <class T> void _print(T var) {cout << var;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ", "; _print(p.ss); cout << "}";}
template <class T> void _print(vector<T> container) {cout << "[ "; for(auto x : container) {_print(x); cout << " ";} cout << "]";}
template <class T> void _print(set<T> container) {cout << "[ "; for(auto x : container) {_print(x); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> container) {cout << "[ "; for (T i : container) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> container) {cout << "[ "; for (auto i : container) {_print(i); cout << " ";} cout << "]";}

vi sieve(int n) {int*arr = new int[n + 1](); vi vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

// 
//-----------------------------------------------------------------------------------------------------------------------------------------------

/*
    Kosaraju Algorithm-
    
    Step 1 : find topo sort using dfs and not bfs.
    Step 2 : Create inverse graph(vertex dir. reversed).
    Step 3 : Nodes which appear first in topo sort. Process that first.
             create a vis array. do dfs from the node and print the dfs.
             when one dfs ends one scc found. Now goto next node in topo sort
             nd if not visited by the second dfs process that as well.
             Do this for all the nodes.

*/


vector<vector<pair<int, int>>> g;
vector<bool> vis;

void dfs(int i, stack<int>& st){
    vis[i] = 1;
    for(auto x : g[i]){
        if(vis[x.ff]==0){
            dfs(x.ff, st);
        }
    }
    st.push(i);
}

void dfs_2(int i, vector<vector<int>>& temp_g){
    vis[i] = 1;
    cout << i << " ";
    for(auto x : temp_g[i]){
        if(vis[x]==0){
            dfs_2(x, temp_g);
        }
    }
}

void solve(int case_num){
    int v, e;
    cin >> v >> e;
    g.resize(v+1);
    vis.resize(v+1);

    for(int i = 0; i<e; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].pb({b, wt});
    }

    stack<int> st;
    dfs(0, st);

    vector<vector<int>> temp_g(v+1);
    for(int i = 0; i<v; i++){
        for(auto x : g[i]){
            temp_g[x.ff].pb(i);
        }
    }

    for(int i = 0; i<=v; i++) vis[i] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node]==0){
            dfs_2(node, temp_g);
            cout << nl;
        }
    }
}


int32_t main(){
    fastio();
    int t = 1;
    //cin >> t;
    rep(i, 1, t+1)
    solve(i);
}    