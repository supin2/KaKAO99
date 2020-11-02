#include <iostream>
#include <string>

using namespace std;

const int MAX_H = 20;
const int MAX_W = 20;

int h, w;
bool board[MAX_H][MAX_W] = {false};


int put(){
    
    // get top left xy
    int y = -1, x = -1;
    for( int i = 0; i < h; i++ ){
        for( int j = 0; j < w; j++){
            if(board[i][j] == false){
                y = i;
                x = j;
                break;
            }
        }
        if( y != -1) break;
    }
    
    if( y == -1 ) return 1;
    int ret = 0;

    // ##
    // #. 
    if( y+1 < h && x+1 < w && !board[y][x] && !board[y][x+1] && !board[y+1][x] ){
        board[y][x] = board[y][x+1] = board[y+1][x] = true;
        ret += put();
        board[y][x] = board[y][x+1] = board[y+1][x] = false;
    }
    
    // ##
    // .#
    if( y+1 < h && x+1 < w && !board[y][x] && !board[y][x+1] && !board[y+1][x+1] ){
        board[y][x] = board[y][x+1] = board[y+1][x+1] = true;
        ret += put();
        board[y][x] = board[y][x+1] = board[y+1][x+1] = false;
    }
    
    // #.
    // ##
    if( y+1 < h && x+1 < w && !board[y][x] && !board[y+1][x] && !board[y+1][x+1] ){
        board[y][x] = board[y+1][x] = board[y+1][x+1] = true;
        ret += put();
        board[y][x] = board[y+1][x] = board[y+1][x+1] = false;
    }
    
    // .#
    // ##
    if( y+1 < h && x-1 >= 0 && !board[y][x] && !board[y+1][x] && !board[y+1][x-1] ){
        board[y][x] = board[y+1][x] = board[y+1][x-1] = true;
        ret += put();
        board[y][x] = board[y+1][x] = board[y+1][x-1] = false;
    }
    
    return ret;
    
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    for( int i = 0 ; i < T ; i++ ){
        
        cin >> h >> w;
        
        for(int i = 0; i < h; i++){
            string tmpStr;
            cin >> tmpStr;
            for(int j = 0; j < w; j++){
                board[i][j] = tmpStr.at(j) == '#' ? true : false ;
            }
        }
        cout << put() << endl ; 
    
    }
    
}
