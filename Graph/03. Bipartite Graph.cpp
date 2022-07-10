#include <bits/stdc++.h>
using namespace std;



/*
Question -> In a class we know which two people are friends. Can you make two section such that
no two people in the class are friends.

Approach -> Each friendship is denoted by an edge in the graph. Now this is question that is the
graph bipartite or is it possible to color graph such that no two neighbours are of same color.

-> Find the minimum numbers of section or is it possible with 3 or 4 section etc. This question
is mathematically complex and can't be coded easily.
*/



vector<vector<int>> g;
vector<int> vis;

bool is_bipartite;

void dfs(int i, int color){
	vis[i] = color;
	for(auto x : g[i]){
		if(vis[x] == color){
			is_bipartite = false;
		}
		else if(!vis[x]) {
			dfs(x, 3-color);
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m; // n nodes and m edges
		cin >> n >> m;
		g.resize(n+1);
		g.clear();
		vis.assign(n+1, 0);
		is_bipartite = true;
		for(int i = 0; i<m; i++){
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i = 1; i<=n; i++){
			if(!vis[i]){
				dfs(i, 1);
			}
		}
		cout << is_bipartite << endl;
	}
}
