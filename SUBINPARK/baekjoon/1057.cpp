#include <iostream>

using namespace std;

int main() {
    int N, person1, person2;
    int round = 1;
    
    cin >> N >> person1 >> person2;
    
    while (true) {
        person1 = (person1 + 1)/2;
        person2 = (person2 + 1)/2;
        
        if (person1 != person2) {
            round++;
            N /= 2;
        } else {
            break;
        }
    }
    if (!N) {
        round = -1;
    }
    cout << round << endl;
}