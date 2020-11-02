#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_PUSHES = 41; 
const int NUM_OF_CLOCKS = 16;
const int NUM_OF_SWITCHES = 10;
int clocks[NUM_OF_CLOCKS] = {0};
bool linkedClock[NUM_OF_SWITCHES][NUM_OF_CLOCKS] = 
{
    /* 0 */ {true,  true,   true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
    /* 1 */ {false, false,  false,  true,   false,  false,  false,  true,   false,  true,   false,  true,   false,  false,  false,  false},
    /* 2 */ {false, false,  false,  false,  true,   false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   true},
    /* 3 */ {true,  false,  false,  false,  true,   true,   true,   true,   false,  false,  false,  false,  false,  false,  false,  false},
    /* 4 */ {false, false,  false,  false,  false,  false,  true,   true,   true,   false,  true,   false,  true,   false,  false,  false},
    /* 5 */ {true,  false,  true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true},
    /* 6 */ {false, false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true},
    /* 7 */ {false, false,  false,  false,  true,   true,   false,  true,   false,  false,  false,  false,  false,  false,  true,   true},
    /* 8 */ {false, true,   true,   true,   true,   true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
    /* 9 */ {false, false,  false,  true,   true,   true,   false,  false,  false,  true,   false,  false,  false,  true,   false,  false}
    
};

bool areAligned(){
    for(int i = 0; i < NUM_OF_CLOCKS; i++){
        if(clocks[i] != 0)
            return false;
    }
    return true;
}

void push(int swtch){
    for(int i = 0; i < NUM_OF_CLOCKS; i++){
        if(linkedClock[swtch][i] == true)
            clocks[i] = (clocks[i] + 3) % 12;
    }
}

int solve(int swtch){
    
    if(swtch == NUM_OF_SWITCHES)
        return areAligned()? 0 : MAX_PUSHES;
    
    int ret = MAX_PUSHES;
    for(int i = 0; i < 4; i++){
        ret = min(ret, i+solve(swtch+1));  // 0번 1번 2번 3번
        push(swtch);                       // 1번 2번 3번 4번
    }
    return ret;
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    for( int i = 0 ; i < T ; i++ ){        
        
        for(int i = 0; i < NUM_OF_CLOCKS; i++){
            cin >> clocks[i];
            clocks[i] %= 12;
        }
        
        int result = solve(0);
        
        if(result == MAX_PUSHES) result = -1;
        
        cout << result << endl;
    
    }
    
}
