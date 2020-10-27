#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> adj;

    adj.resize(8);

    adj[1].push_back(2);
    adj[3].push_back(0);
    adj[5].push_back(6);
    adj[7].push_back(4);
    
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j]) {
                cout << 0 << " ";
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }

    // for (int i = 0; i < 5; ++i) {
    //     for (int j = 0; j < i; ++j) {
    //         cout << i  <<  ',' << j << endl;
    //     }
    //         cout << endl;
    // }

    return 0;
}