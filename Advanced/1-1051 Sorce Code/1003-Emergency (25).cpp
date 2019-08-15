#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_LEN 501
#define INF     999999

using namespace std;



int Map[MAX_LEN][MAX_LEN]; 
bool used[MAX_LEN];
int gether[MAX_LEN];
int paths[MAX_LEN];
int dist[MAX_LEN];

void solve() {
    fill(Map[0], Map[0] + MAX_LEN * MAX_LEN, INF);
    fill(dist, dist + MAX_LEN, INF);
    int N, M, Start, Em, Mem[MAX_LEN], from, to, cost;
    cin >> N >> M >> Start >> Em;
    
    for(int i = 0; i < N; i++) {
        cin >> Mem[i];
    }
    
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> cost;
        Map[from][to] = cost;
        Map[to][from] = cost;
    }
    
    //Dijkstra

    gether[Start]   = Mem[Start];
    dist[Start]     = 0;
    paths[Start]    = 1;

    while(true) {
        int v = -1;
        for(int u = 0; u < N; u++) {
            if(!used[u] && (v == -1 || dist[u] < dist[v]))
                v = u;
        }

        if(v == -1) break;
        used[v] = true;

        
        for(int u = 0; u < N; u++) {
            if(dist[u] > dist[v] + Map[v][u]) {
                dist[u]     = dist[v] + Map[v][u];
                gether[u]   = gether[v] + Mem[u];
                paths[u]    = paths[v];
            } else if(dist[u] == dist[v] + Map[v][u]) {
                paths[u] += paths[v];
                if(gether[u] < gether[v] + Mem[u])
                    gether[u] = gether[v] + Mem[u];
            }
        }
        
    }
    cout << paths[Em] << " " << gether[Em] << endl;

}

int main() {
    solve();
    return 0;
}
