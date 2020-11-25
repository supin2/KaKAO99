#include <iostream>
#include <cstring>
using namespace std;

/*

0 1 1 1 0
1 0 0 0 1
1 0 0 0 0
1 0 0 0 0
0 1 0 0 0

0 + 1/2 + 1 + 1 + 0     1/2
1/3 + 0 + 0 + 0 + 1     4/15
1/3 + 0000              1/15
1/3 + 0000              1/15
0 + 1/2 + 000           1/10

*/

int main(){
    int c, n, d, p, t, ans;
    cin >> c;
    while(c--){
        double village[50][50]={0.0}, escape[50][50]={0.0};
        double pct[50]={0.0}, result[50]={0.0}, temp[50]={0.0};
        cin >> n >> d >> p;
        
        for(int i=0;i<n;i++)if(i==p)result[i]=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> village[i][j];
                if(village[i][j]!=0.0)pct[i]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){                
                if(village[i][j]!=0){
                    escape[i][j] = 1/pct[i];
                }
            }
        }

        while(d--){
            memset(temp, 0, sizeof(temp));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i] += result[j] * escape[j][i];
                }
            }
            memcpy(result, temp, sizeof(result));
        }
        cin >> t;
        cout.precision(8);
        while(t--){
            cin >> ans;            
            cout << result[ans] << " ";
        }
        cout<<endl;
    }
}