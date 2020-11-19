#include <iostream>
using namespace std;

int main(){
    int N;
    int colors[1000][3];
    int money[1000][3];
    cin>>N;
    for(int i=0;i<N;i++){
        cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
    }
    money[0][0] = colors[0][0];
    money[0][1] = colors[0][1];
    money[0][2] = colors[0][2];
    for(int i=1;i<N;i++){
        money[i][0] = min(money[i-1][1], money[i-1][2]) + colors[i][0];
        money[i][1] = min(money[i-1][0], money[i-1][2]) + colors[i][1];
        money[i][2] = min(money[i-1][0], money[i-1][1]) + colors[i][2];
    }
    cout << min(money[N-1][0], min(money[N-1][1], money[N-1][2]));
}