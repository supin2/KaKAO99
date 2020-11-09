#include <iostream>
#include <limits>

using namespace std;

const int MAX_N_M = 100+1; // 배열을 한칸씩 더하지 않으면 0을 선택했을 경우와 선택하지 않았을 경우를 구분할 수 없음.
const long long NEGINF = numeric_limits<long long>::min();
int n, m;

int A[MAX_N_M];
int B[MAX_N_M];
int cache[MAX_N_M][MAX_N_M];
// vector<int> cacheA;
// vector<int> cacheB; 
// cache를 따로 선언하면 A, B중에 어떤 건이 선행하는 건지 매번계산해야함
// 모든 경우의 수를 표현할 수 없음. A와 B 각각의 lis는 알 수 있어도 A와 B가 조합된 lis 표현 불가

int jlis(int indexA, int indexB){
    
    int& ret = cache[indexA][indexB];
    if(ret != -1) return ret;
    ret = 0;
    
    int curr = max(A[indexA], B[indexB]); 
    for(int i = indexA + 1; i <= n; i++){
        if(curr < A[i])
            ret = max(ret, 1+jlis(i, indexB));
    }
    for(int i = indexB + 1; i <= m; i++){
        if(curr < B[i])
            ret = max(ret, 1+jlis(indexA, i));
    }
    
    return ret;
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    for( int i = 0 ; i < T ; i++ ){
        
        cin >> n >> m;
        fill(&cache[0][0], &cache[MAX_N_M - 1][MAX_N_M], -1);
        
        A[0] = NEGINF;
        for( int j = 1 ; j <= n ; j++ ){
            cin >> A[j];
        }

        B[0] = NEGINF;
        for( int j = 1 ; j <= m ; j++ ){
            cin >> B[j];
        }
    
        int result = 1; // default 2 -> 1
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                int length = jlis(i, j);
                result = length > result ? length : result;
            }
        }
    
        cout << result << endl ; 
    
    }
    
}
