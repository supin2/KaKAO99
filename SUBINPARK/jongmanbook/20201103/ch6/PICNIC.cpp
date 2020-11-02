#include <iostream>
#include <cstring>

using namespace std;

int tot_case, n, m;
bool areFriends[10][10];
bool taken[10];

int countParirings(bool taken[10]) {
    int firstFree = -1;

    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;
    int ret = 0;

    for (int i = firstFree + 1; i < n; ++i) {
        if (!taken[i] && areFriends[firstFree][i]) {
            taken[firstFree] = taken[i] = true;
            ret += countParirings(taken);
            taken[firstFree] = taken[i] = false;
        }
    }

    return ret;
}



int main() {
    cin >> tot_case;

    if (tot_case > 50 || tot_case < 0) {
        cout << -1;
    }

    for (int i = 0; i < tot_case; i++) {
        cin >> n >> m;

        if (n < 2 || n > 10 || m < 0 || m > (((n)*(n - 1)) / 2)) { 
            cout << -1;
        }

        memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));

        for (int j = 0; j < m; j++) {
            int friend1, friend2;

            cin >> friend1 >> friend2;
            areFriends[friend1][friend2] = true;
            areFriends[friend2][friend1] = true;
        }
        cout << countParirings(taken) << endl;
    }
    return 0;
}