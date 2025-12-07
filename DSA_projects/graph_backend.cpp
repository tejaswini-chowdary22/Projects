#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    vector<string> building = {
        "Main Gate","Admin Block","Classroom Block",
        "Library","Hostel","Canteen","Sports Complex"
    };

    int g[7][7] = {
        {0,3,5,0,0,0,7},
        {3,0,2,4,0,0,0},
        {5,2,0,3,4,0,0},
        {0,4,3,0,0,2,0},
        {0,0,4,0,0,3,5},
        {0,0,0,2,3,0,4},
        {7,0,0,0,5,4,0}
    };

    int n = building.size();

    cout << "Enter source index: ";
    int src; cin >> src;

    vector<int> dist(n,INF), parent(n,-1), used(n,0);
    dist[src]=0;

    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++)
            if(!used[j] && (u==-1 || dist[j] < dist[u])) u=j;

        used[u]=1;

        for(int v=0;v<n;v++){
            if(g[u][v]>0){
                int nd = dist[u] + g[u][v];
                if(nd < dist[v]){
                    dist[v]=nd;
                    parent[v]=u;
                }
            }
        }
    }

    cout << "\nDistances from " << building[src] << ":\n";
    for(int i=0;i<n;i++)
        cout << building[i] << " : " << dist[i] << "\n";

    return 0;
}
