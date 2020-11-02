#include <iostream>
#include <vector>

using namespace std;

const int MAX_g = 1000;


vector<int> adj[MAX_g];
vector<bool> visited;

int g, h;
int installed;

const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int dfs(int vertex) {
    
    visited[vertex] = true;
    
    int status = UNWATCHED;
    
    for( int i = 0 ; i < adj[vertex].size() ; i++ ){
        int child = adj[vertex][i];
        if( !visited[child] ){
            
            int childStatus = dfs(child);
            
            if( status != INSTALLED ){
                if( childStatus == UNWATCHED ){
                    status = INSTALLED;
                    installed++;
                }    
                else if( childStatus == INSTALLED )
                    status = WATCHED;
            }
        }
    }
    
    return status;
}

int installCamera(){
    installed = 0;
    visited = vector<bool>(g, false);
    for( int i = 0 ; i < g ; i++ ){
        if( !visited[i] && dfs(i) == UNWATCHED )
            installed++;
    }
    
    return installed;
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    for( int i = 0 ; i < T ; i++ ){
        
        cin >> g >> h;
        
        for( int j = 0 ; j < g ; j++ ){
            adj[j].clear();
        }
        
        for( int j = 0 ; j < h ; j++ ){
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
    
        cout << installCamera() << endl ; 
    
    }
    
}
