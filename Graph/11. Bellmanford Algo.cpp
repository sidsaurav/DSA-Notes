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

vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> par;

//Here we have considered case where SSSP is calculated from vertex x then x is
//abandoned node. If abandoned then it is possible that cycle exists and we may
//not find it. In such case make a temp node connect it with all nodes with weight 0
//and find SSSP from this temp node.

void solve(int case_num){
    int v, e;
    cin >> v >> e;
    g.clear();
    dist.clear();
    par.clear();
    g.resize(v+1);
    dist.resize(v+1, 1e9);
    par.resize(v+1, -1);

    for(int i = 0; i<e; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].pb({b, wt});
    }

    dist[0] = 0;

    for(int i = 0; i<v-1; i++){
        for(int j = 0; j<v; j++){
            for(auto x : g[j]){
                if(dist[x.ff] > dist[j] + x.ss){
                    dist[x.ff] = dist[j] + x.ss;
                    par[x.ff] = j;
                }
            }
        }
    }
    for(int i = 0; i<v; i++){
        cout << "dist of " << i << " is -> " << dist[i] << nl;
    }

    //Negative Cycle detection -
    bool negCycle = 0;
    for(int i = 0; i<v; i++){
        for(auto x : g[i]){
            if(dist[x.ff]>dist[i]+x.ss) negCycle = true;
        }
    }

    if(negCycle){
        cout << "There is a negative cycle" << nl;
    }
    else {
        cout << "There is no negative cycle" << nl;
    }
}

int32_t main(){
    fastio();
    int t = 1;
    //cin >> t;
    rep(i, 1, t+1)
    solve(i);
}    