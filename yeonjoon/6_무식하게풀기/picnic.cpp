#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10;
int n, m;

vector<int> areFriends[MAX_N];
vector<bool> taken;

int getFirst(vector<bool> taken){
    for( int i = 0; i < taken.size(); i++ ){
        if(taken[i] == false)
            return i;
    }   
    return -1;
}

int matchFriends(vector<bool> taken){
    
    int ret = 0;
    int firstStudent = getFirst(taken);
    
    if(firstStudent == -1) // 대기학생이 없는 경우
        return 1;
    
    vector<int> friends = areFriends[firstStudent];
    for(int i = 0; i < friends.size(); i++){
        
        if(!taken[friends[i]]){
            taken[firstStudent] = taken[friends[i]] = true;
            ret += matchFriends(taken);
            taken[firstStudent] = taken[friends[i]] = false;
        }
    }
    
    return ret;
    
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    for( int i = 0 ; i < T ; i++ ){
        
        cin >> n >> m;
        taken = vector<bool>(n, false);
        
        //2차원 vector 초기화
        for( int j = 0 ; j < n ; j++ ){
            areFriends[j].clear();
        }
        
        //친구 관계 설정
        for( int j = 0 ; j < m ; j++ ){
            int s1, s2;
            cin >> s1 >> s2;
            areFriends[s1].push_back(s2);
            areFriends[s2].push_back(s1);
        }
    
        cout << matchFriends(taken) << endl ; 
    
    }
    
}
