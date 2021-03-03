#include <iostream>
#include <stack>
using namespace std;

string solution(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push('(');
        } else if (str[i] == '{') {
            st.push('{');
        } else if (str[i] == '[') {
            st.push('[');
        } else if (str[i] == ')') {
            if (st.empty()) return "NO";
            if (st.top() == '(') st.pop();
        } else if (str[i] == '}') {
            if (st.empty()) return "NO";
            if (st.top() == '{') st.pop(); 
        } else if (str[i] == ']') {
            if (st.empty()) return "NO";
            if (st.top() == '[') st.pop();
        }
    }
    if (st.empty()) return "YES";
    else return "NO";
}


int main() {
    int C;

    cin >> C;

    for (int i = 0; i < C; i++) {
        string str;
        cin >> str;
        cout << solution(str) << '\n';
    }

}