#include <bits/stdc++.h>
using namespace std;

// 1. DFS Way

// vector<int> g[100010];

// vector<int> topo;
// vector<int> vis(100010);

// void dfs(int i){
//     vis[i] = 1;

//     for(auto x : g[i]){
//         if(!vis[x]){
//             dfs(x);
//         }
//     }

//     topo.push_back(i);
// }


// int main(){
//     int n;
//     cin >> n;
//     for(int i = 1; i<=n; i++){
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//     }

//     for(int i = 1; i<=n; i++){
//         if(!vis[i]){
//             dfs(i);
//         }
//     }
//     reverse(topo.begin(), topo.end());
//     for(auto x : topo){
//         cout << x << " ";
//     }
//     cout << endl;
// }

// 2. BFS Way

vector<int> g[100010];
vector<int> indegree(100010);
vector<int> topo;
int n;

void kahn(){
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        topo.push_back(fr);
        for(auto x : g[fr]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b] += 1;;
    }
    kahn();
    for(auto x : topo) cout << x << " ";
    cout << endl;
}

/*
1. Kahn Algo help in detecting cycle in directed graph. First find topo array. If graph contain
a cycle then those nodes which form cycle will not appear in topo array hence size of topo array
will be less than n.

2. Find lexicographically smallest topo ordering. Use priority queue in place of queue.
*/