//Author : Siddharth Saurav (Chem 23)

#include <bits/stdc++.h>
using namespace std;


/*
Question -> Given simple graph. Calculate number of edges you can draw so that
number of components in the graph decreases.

Approach -> We will use calculate num of components and in each components we will find number
vertices. Then we will process that. We can find this using a little twisted DFS. In vis vector
we will store conn compo num instead of just putting 1 and 0.
*/

vector<vector<int>> g;
vector<int> vis;

// Better DFS-----------------------------


void dfs(int i, int compo){
	vis[i] = compo;
	for(auto x : g[i]){
		if(!vis[x]){
			dfs(x, compo);
		}
	}
}

//----------------------------------------

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m; // n nodes and m edges
		cin >> n >> m;
		g.resize(n+1);
		g.clear();
		vis.assign(n+1, 0);
		for(int i = 0; i<m; i++){
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int compo = 0;
		for(int i = 1; i<=n; i++){
			if(!vis[i]){
				compo++;
				dfs(i, compo);
			}
		}
		vector<int> num_ele(compo+1);
		for(int i = 1; i<=n; i++){
			num_ele[vis[i]]++;
		}
		int res = 0, sum = 0;
		for(int i = 1; i<compo; i++){
			sum += num_ele[i];
			res += sum*num_ele[i+1];
		}
		cout << res << endl;
	}
}

// Time Complexity of DFS -> O(V+E)

// void dfs(int i, int compo){
// 	vis[i] = compo; //This is executed V times
// 	for(auto x : g[i]){ //Total iterations of this loop for all vertices is number of neighbour
// 		if(!vis[x]){//which is equal to 2*E so O(V+2E) == O(V+E)
// 			dfs(x, compo);
// 		}
// 	}	
// }



//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------