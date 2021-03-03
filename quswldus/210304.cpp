#include <iostream>

using namespace std;

int main()
{
    int C, index, a=1, b=1, c=1;
    string in;
    cin >> C;
    getline(cin,in);
    while(C-- > 0){
        getline(cin,in);
        index = 0;
        while(index < in.length()){
            switch (in.at(index++)){
                case '{':
                    a++;
                    break;
                case '[':
                    b++;
                    break;
                case '(':
                    c++;
                    break;
                case '}':
                    a--;
                    break;
                case ']':
                    b--;
                    break;
                case ')':
                    c--;
                    break;
                default:
                    a-=10;
            }
            if(a*b*c<=0)index = in.length()+1;
        }
        if(index == in.length() && a*b*c==1)cout<<"YES";
        else cout<<"NO";
    }
}
