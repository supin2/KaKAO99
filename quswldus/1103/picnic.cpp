#include<iostream>
#include<cstring>
using namespace std;

int n, m;
bool frd[10][10];

int picnic(bool alone[10]){
    int child=-1;
    for(int i=0;i<n;i++)if(alone[i]){
        child=i;
        break;
    }
    if(child==-1)return 1;
    int count = 0;
    for(int j=child+1;j<n;j++)if(alone[j]&&frd[child][j]){
        alone[child]=alone[j]=false;
        count += picnic(alone);
        alone[child]=alone[j]=true;
    }
    return count;
}

int main(){
    int C;
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>n>>m;
        memset(frd, 0, sizeof(frd));
        for(int j=0;j<m;j++){
            int x, y;
            cin>>x>>y;
            frd[x][y]=frd[y][x]=true;        
        }        
    }
    bool alone[10];
    memset(alone, 1, sizeof(alone));
    cout<<picnic(alone)<<endl;
}