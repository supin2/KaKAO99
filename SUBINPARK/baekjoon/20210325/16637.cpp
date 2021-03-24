#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int N, ans = INT_MIN;
string expr;


// ex) 3 + 8 * 7 - 9 * 2
// 1. 괄호 씌우고 넘기기 : (3 + 8) * 7 - 9 * 2
// 2. 괄호 안씌우고 넘기기 : 3 + 8 * 7 - 9 * 2

int calculate(int a, int b, char oper) {
    switch (oper) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case '*' :
            return a * b;
    }
}

void solution(int idx, int cur_tot) { // idx : 수식 배열 index, cur_tot : 계속 더해가는 수식 값
    if (idx > N - 1) {
        ans = max(ans, cur_tot);
        return;
    }

    char oper = (idx == 0) ? '+' : expr[idx - 1];

    if (idx + 2 < N) { // 괄호 씌우기
        int paren = calculate(expr[idx] - '0', expr[idx + 2] - '0', expr[idx + 1]);
        solution(idx + 4, calculate(cur_tot, paren, oper));
    }
    solution(idx + 2, calculate(cur_tot, expr[idx] - '0', oper)); // 그냥 넘기기
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> expr;
    
    solution(0, 0);

    cout << ans << '\n';

    return 0;
}