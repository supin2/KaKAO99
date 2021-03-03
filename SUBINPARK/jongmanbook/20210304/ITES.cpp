#include <iostream>
#include <queue>

using namespace std;

int C, K, N;

struct RNG {
    unsigned seed;

    RNG() : seed(1983) {}

    unsigned next() {
        unsigned result = seed;
        seed = ((seed * 214013u) + 2531011u);
        return result % 10000 + 1;
    }
};

int countRanges(int k, int n) {
    RNG rng; 

    queue<int> range; 

    int result = 0, rangeSum = 0;

    for (int i = 0; i < n; i++) {
        int newSignal = rng.next();

        rangeSum += newSignal;
        range.push(newSignal);

        while (rangeSum > k) {
            rangeSum -= range.front();
            range.pop();
        }

        if (rangeSum == k) result++;
    }
    return result;
}

int main(void) {
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> K >> N;
        cout << countRanges(K, N) << endl;
    }
    return 0;
}