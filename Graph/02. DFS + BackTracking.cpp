//Author : Siddharth Saurav (Chem 23)

// https://www.youtube.com/watch?v=PSy0yJQx050


#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define nl endl

int n;
int k;
int num;
vector<vector<pair<int, int>>> g;
int src;
int dest;
vector<int> vis;

string smallest;
int smallest_wt = INT_MAX;

string largest;
int largest_wt = INT_MIN;

string just_larger;
int just_larger_wt = INT_MAX;

string just_smaller;
int just_smaller_wt = INT_MIN;

set<pair<int, string>> s;

void dfs(int src, int sum, string path){
    //
    if(src == dest){
        if(smallest_wt>sum){
            smallest = path;
            smallest_wt = sum;
        }

        if(largest_wt<sum){
            largest = path;
            largest_wt = sum;
        }
        if(sum>num and sum<just_larger_wt){
            just_larger_wt = sum;
            just_larger = path;
        }


        if(sum<num and sum>just_smaller_wt){
            just_smaller_wt = sum;
            just_smaller = path;
        }

        s.insert({sum, path});
        return;
    }

    //
    vis[src] = 1;
    for(auto x : g[src]){
        if(vis[x.ff] == 0){
            dfs(x.ff, sum+x.ss, path+"-"+to_string(x.ff));
        }
    }
    vis[src] = 0;
}

void solve(){
    cin >> n;
    g.resize(n+1);
    vis.resize(n+1);
    int e;
    cin >> e;
    for(int i = 0; i<e; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
        g[b].push_back({a, wt});
    }
    cin >> src;
    cin >> dest;
    cin >> num;
    cin >> k;

    dfs(src, 0, to_string(src));

    cout << smallest_wt << nl;
    cout << smallest << nl << nl;
    
    cout << largest_wt << nl;
    cout << largest << nl << nl;

    cout << just_larger_wt << nl;
    cout << just_larger << nl<<nl;

    cout << just_smaller_wt << nl;
    cout << just_smaller << nl << nl;

    auto it = s.rbegin();
    for(int i = 0; i<k-1; i++){
        it++;
    }

    // deb(s);
    cout << (*it).ff << nl;
    cout << (*it).ss << nl;
}

int32_t main(){
    solve();
}    