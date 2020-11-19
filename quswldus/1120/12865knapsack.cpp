#include <iostream>
using namespace std;

int main(){
    int N, K;
    int bag[101][100001], weight[101], value[101];
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> weight[i] >> value[i];        
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            bag[i][j] = bag[i-1][j];
            if(weight[i-1] <= j){
                bag[i][j] = max(bag[i-1][j], bag[i-1][j-weight[i-1]] + value[i]);
            }
        }
    }
    cout << bag[N][K] << endl;
}