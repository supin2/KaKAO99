#include <iostream>

using namespace std;

const int MAX_K = 100000;
const int MAX_N = 100;

int things[MAX_N+3][2];
int cache[MAX_K+5][MAX_N+5];

const int WEIGHT = 0;
const int VALUE = 1;

// int cnt = 0;

int knapsack(int index, int capacity){
    
    // int tmp = ++cnt;
    
    // cout << tmp << " " << index << ", " << capacity << endl;
    
    if( index == 0)
        return 0;
        
    int& ret = cache[capacity][index];
    if(ret != -1 )
        return ret;
    
    //물건을 담지 않을 경우
    ret = knapsack(index-1, capacity);

    // 물건을 담을 경우
    if(capacity >= things[index][WEIGHT])
        ret = max(ret, (knapsack(index-1, capacity-things[index][WEIGHT]) + things[index][VALUE]));
    
    // cout << tmp << " " << ret << endl;
    return ret;
}

int main()
{
    int N, K; 
    cin >> N >> K;
    
    fill(&cache[0][0], &cache[MAX_K+3][MAX_N+3], -1);
    
    for( int i = 1 ; i <= N ; i ++ ){
        
        cin >> things[i][WEIGHT] >> things[i][VALUE];
    
    }
    
    cout << knapsack(N, K);
    
}
