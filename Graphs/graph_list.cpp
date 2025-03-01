#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<vector<int>>& vec){
    for (int i = 1; i < vec.size(); ++i){
        cout << i << " -> ";
        for (int j = 0; j < vec[i].size(); ++j){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> bfs(int V, vector<vector<int>>& adj){
    vector<int> vis(V + 1, 0); // Use a vector instead of an array
    queue<int> q;
    vector<int> bfs_result;

    vis[1] = 1;  // Start BFS from node 1 (not 0)
    q.push(1);

    while (!q.empty()){
        int node = q.front();
        q.pop();
        bfs_result.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }   

    return bfs_result;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > n || v < 1 || v > n) {
            cerr << "Invalid edge: " << u << " " << v << endl;
            return 1;  
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    print(adj);
    
    vector<int> vec = bfs(n, adj);

    cout << "BFS Traversal: ";
    for (int node : vec){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
