#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string N;

int classify(int a, int b){
    string M = N.substr(a, b-a+1);
    bool progressive = true;
    bool alternating = true;
    if(M==string(M.size(), M[0])) return 1;
    for(int i=0;i<M.size()-1;++i)if(M[i+1]-M[i] != M[1]-M[0])
        progressive = false;
    if(progressive && abs(M[1]-M[0])==1) return 2;
    for(int i=0;i<M.size();++i)if(M[i] != M[i%2])
        alternating = false;
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}

int cache[10002];
//pi(in) = L=3~5min( pi(in+L) + classify(Nbegin,L) )
int pi(int in){
    if(in==N.size()) return 0;
    int& ret = cache[in];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int L=3;L<=5;++L)if(in+L <= N.size())
        ret = min(ret, pi(in+L) + classify(in, in+L-1));
    return ret;
}

int main(){
    int C, tmp;
    int ret[50];
    cin >> C;

    for(int i=0;i<C;i++){
        cin >> tmp;
        N = to_string(tmp);
        memset(cache, -1, sizeof(cache));
        ret[i] = pi(0);
    }
    for(int i=0;i<C;i++){
        cout << ret[i] << endl;
    }
}