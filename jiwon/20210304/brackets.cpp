#include <iostream>
#include <algorithm>
#include <cstring> 
#include <stack>

using namespace std;
int N; // number of test cases

string solution(string str) {
  stack<char> stack;
  string ret = "YES";
  
  for (int i = 0; i < str.length(); i++) {
    char temp = str[i];
    if (temp == '}' || temp == ')' || temp == ']') {
      if (stack.empty()) {
        ret = "NO";
        break;
      }
    }
    if (temp == '{' || temp == '(' || temp == '[') {
      stack.push(temp);
    } else if (temp == '}') {
      if (stack.top() == '{') stack.pop();
      else {
        ret = "NO";
        break;
      }
    } else if (temp == ')') {
      if (stack.top() == '(') stack.pop();
      else {
        ret = "NO";
        break;
      }
    } else if (temp == ']') {
      if (stack.top() == '[') stack.pop();
      else {
        ret = "NO";
        break;
      }
    }
  }
  if (!stack.empty()) ret = "NO";
  return ret;
}

int main() {
  // cout << "Hello, World!";
  cin >> N;
  string outputs[101];

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    outputs[i] = solution(input);
  }
  for (int i = 0; i < N; i++) {
    cout << outputs[i] << endl;
  }
  return 0;
}