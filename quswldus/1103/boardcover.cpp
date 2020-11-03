#include<iostream>
#include<vector>
using namespace std;

// 주어진 칸을 덮을 수 있는 4가지 방법
// 블록을 구성하는 3칸의 상대적 위치 (dy,dx) 의 목록
const int coverType[4][3][2] = {
  { { 0, 0 }, { 1, 0 }, { 0, 1 } },
  { { 0, 0 }, { 0, 1 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, -1 } }};

bool set(vector<vector<int>>& board, int y, int, x, int type, int delta){
    bool ok = true;
    for(int i=0;i<3;++i){
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny<0||ny>=board.size()||nx<0||nx>=board[0].size())
            ok=false;
        else if (board[ny][nx]+=delta > 1)
            ok=false;
    }
    return ok;
}

int boardCover(vector<vector<int>>& board){
    int y=-1,x=-1;
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[i].size();++j)
            if(board[i][j]==0){
                y=i;
                x=j;
                break;
            }
        if(y != -1)break;
    }
    if(y == -1)return 1;
    int result = 0;
    for(int type =0;type<4;++type){
        if(set(board, y, x, type, 1))result+=cover(board);
        set(board, y, x, type, -1);
    }
    return result;
}

int main(){
    int C, H, W;
    string tmp;
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>H>>W;
        vector<vector<int>> board(H, vector<int>(W,0));
        for(int j=0;j<H;j++){
            for(int k=0;k<W;k++){
                cin>>tmp;
                if(tmp=="#")board[j][k]=1;
            }
        }
        cout<<boardCover(board)<<endl;        
    }
}