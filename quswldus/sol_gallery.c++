#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAX_V = 1000;

int V;
vector<int> adj[MAX_V];

vector<bool> visited;

const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;

int dfs(int here){
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i=0;i<adj[here].size();++i){
        int there = adj[here][i];
        if(!visited[there])
            ++children[dfs(there)];
    }
    if(children[UNWATCHED]){
        ++installed;
        return INSTALLED;   
    }
    if(children[INSTALLED])
        return  WATCHED;
    return UNWATCHED;
}

int installCamera(){
    installed = 0;
    visited = vector<bool>(V, false);
    for(int u=0;u<V;++u)
        if(!visited[u] && dfs(u) == UNWATCHED)
            ++installed;
    return installed;
}

int main(){
    int cases;
    cin >> cases;
    for(int cc=0;cc<cases;++cc){
        int E;
        cin >> V >> E;
        for(int i=0;i<V;++i)adj[i].clear();
        for(int i=0;i<E;++i){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << installCamera() << endl;
    }
}