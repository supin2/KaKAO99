#include<iostream>
#include<vector>
using namespace std;

const int MAXCASE = 9999;
const int buttons[10][16]={
  {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
  {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},//1
  {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},//2
  {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},//3
  {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},//4
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},//5
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},//6
  {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},//7
  {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},//8
  {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0},//9
};

bool synced(const vector<int>& clocks){
    for(int i=0;i<16;i++)
        if(clocks[i]%4 != 0)return false;
    return true;
}

void butOn(vector<int>& clocks, int button){
    for(int i=0;i<16;++i)
        if(buttons[button][i])
            clocks[i] += 3;
}

int clocksync(vector<int>& clocks, int button){
    if(button==10)return synced(clocks)?0:MAXCASE;
    int result = MAXCASE;
    for(int i=0;i<4;++i){
        result = min(result, i+clocksync(clocks, button+1));
        butOn(clocks, button);
    }
    return result;
}

int main(){
    int C;
    cin>>C;
    for(int i=0;i<C;i++){
        vector<int> clocks(16, 0);
        for(int j=0;j<16;j++)
            cin>>clocks[j];
        int result = clocksync(clocks,0);
        cout<<(result >= MAXCASE ? -1 : result)<<endl; 
    }
}