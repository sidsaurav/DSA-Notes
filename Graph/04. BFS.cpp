//Author : Siddharth Saurav (Chem 23)

#include <bits/stdc++.h>
using namespace std;


/*Question - You are in a maze and given one start point and one exit point. There is a monster in the
maze and you are given co-ordinate of the monster. Find wheter you would be able to flee.

Approach->Basically find shortest path from you to exit and shortest path from monster to exit. If you
are closer then you would flee other wise monster will get to exit first and wait there for you.
Shortest path can be found using BFS.

*/

vector<string> g;
vector<vector<int>> dist;
vector<vector<pair<int, int>>> parent;
int n, m;
int a, b, x, y; //a b -> start point, x y - end point

void printPath(int, int);

bool valid(int i, int j){
    return i>=0 and i<n and j>=0 and j<m and g[i][j] != '#';
}


//movement vectors 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    cin >> n >> m;
    g.resize(n);
    for(auto &x : g) cin >> x;
    cin >> a >> b >> x >> y;
    dist.resize(n, vector<int> (m,1e9));
    parent.resize(n, vector<pair<int, int>> (m,{0,0}));

    queue<pair<int, int>> q;
    q.push({a, b});
    dist[a][b] = 0;
    parent[a][b] = {-1, -1};

    int cnt = 0;
    while(!q.empty()){
        cnt++; // count denotes current layer distance.
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for(int i = 0; i<4; i++){
                if(valid(x+dx[i], y+dy[i]) and dist[x+dx[i]][y+dy[i]] >  dist[x][y]+1){
                    dist[x+dx[i]][y+dy[i]] =  dist[x][y]+1;
                    parent[x+dx[i]][y+dy[i]] = {x, y};
                    q.push({x+dx[i], y+dy[i]});
                }
            }
        }
    }
    cout << dist[x][y] << endl;
    printPath(5, 0);
}

// BFS gives shortest path from a node to every other node in unweighted graph.

// Time Complexity -> O(V+E)


//Utility function to print the path.

void printPath(int i, int j){
    if(parent[i][j] == make_pair(-1, -1)){
        cout << i << " " << j << endl;
        return;
    }    

    cout << i << " " << j << endl;
    printPath(parent[i][j].first, parent[i][j].second);
}

/*
2 concepts (isvalid and cnt concept) read comments- 
https://leetcode.com/submissions/detail/728436524/
*/




/*
In the above question there are variations-
1.multiple exit path -> Question of game theory.
2.multiple monsters -> If dist to destination is smaller than all monster's dist to dest
then you can flee.
3.multiple start point -> multisource BFS.


Question -> You are given multiple start points and multiple end points. Find smallest
dist between any two start and end point. Use concept of pseudo node. Connect all source 
with a pseudo node and all dest with another pseudo node and ans will be dist between
pseduonode - 2. multisource and multidest BFS.
BFS.
*/




/*
One config to another config in shortest number of moves if we know next moves.
apply bfs in these type of questions.
https://leetcode.com/problems/sliding-puzzle/
*/
