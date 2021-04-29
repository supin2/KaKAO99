#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAX_NM = 15;
const int ARCHER = 3;
int N, M, D;
int field[MAX_NM][MAX_NM];
bool attacked[MAX_NM][MAX_NM];
bool result[MAX_NM][MAX_NM];

int count(bool result[MAX_NM][MAX_NM]){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(result[i][j])
                cnt++;
        }
    }
    return cnt;
}

int attack(vector<int> placement){
    
    int cnt = 0;
    fill_n(&result[0][0], MAX_NM*MAX_NM, false);
    
    int y = N;
    while(y > 0){
        fill_n(&attacked[0][0], MAX_NM*MAX_NM, false);
        for(int x = 0; x < M; x++){
            bool found = false;
            if(placement[x] == 1){
                for(int dist = 1; dist <= D; dist++){
                    for(int i = -(dist-1); i <= dist-1; i++){
                        if(x+i < 0 || x+i >= M || y-(dist-abs(i)) < 0)
                            continue;
                        if(result[y-(dist-abs(i))][x+i])
                            continue;
                        if(field[y-(dist-abs(i))][x+i] == 1){
                            attacked[y-(dist-abs(i))][x+i] = true;
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!result[i][j] && attacked[i][j]){
                    cnt++;
                    result[i][j] = attacked[i][j];
                }
            }
        }
        y--;
    }
    return cnt;
}


int sol(){
    vector<int> placement;
    for(int i= 0; i < M-3; i++)
        placement.push_back(0);
    for(int i = 0; i < 3; i++) 
        placement.push_back(1);
        
    int max = 0;    
    int enemy = 0;
    do{
        enemy = attack(placement);
        if(enemy > max)
            max = enemy;

	}while(next_permutation(placement.begin(), placement.end()));
	
	placement.clear();
	return max;
    
}


int main()
{
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> field[i][j];
        }
    }
    cout << sol();

}
