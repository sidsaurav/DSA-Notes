/*
Articulation Point
1. we will require 3 array -> parent, discovery num, lowest disc no which the node can touch excluding
current path.
2. initialise parent with -1 and low with 1e9
3. start dfs from any node.
    a. mark visited
    b. iterate its nbr and assign low to disc num -> two case 
        (i) if nbr is vis and not parent, update low with disc no. of that nbr
        (ii) if nbr is not visited. mark parent. do dfs. update low with low of its nbr while backtracking 
             in the same else case check if(low[nbr]>=disc[src]) agr aesa h to ap[src] = true
    c. for the node where dfs began check if no. of dfs call >= 2 if so ap[src] = true qki ek call me pure
       graph ko cover ni kr paya mtlb graph two diff part me divided hoga about that src.
*/

/*
Bridge
Bridge aur articulation point me sirf equal to sign ka diff h. equal to hata do bridge ka code bnn jaega.
Source node ko alag se handle krne ki jrurat nhi h.
*/



vector<vector<int>> adj;

vector<int> par;
vector<int> disc;
vector<int> low;

vector<bool> vis;
vector<bool> ap;

int d_cnt = 1;


void dfs(int src){
    vis[src] = 1;
    disc[src] = d_cnt;
    d_cnt++;
    int dfs_cnt = 0;
    for(auto x : adj[src]){
        if(vis[x]==1 and x != par[src]){
            low[src] = min(low[src], disc[x]);
        }
        else if(vis[x]==0){
            par[x] = src;
            dfs_cnt++;
            dfs(x);
            low[src] = min(low[src], low[x]);


            if(par[src] == -1){
                if (dfs_cnt>=2) ap[src] = 1; // for the dfs source vertex
            }
            else if(low[x]>=disc[src]) ap[src] = 1; // for rem. vertex
        }
    }
}


void solve(int case_num){
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    par.resize(n+1, -1);
    vis.resize(n+1);
    ap.resize(n+1);
    disc.resize(n+1);
    low.resize(n+1, 1e9);
    for(int i = 0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i = 1; i<=n; i++){
        cout << i << " -> " << ap[i] << endl;
    }
}