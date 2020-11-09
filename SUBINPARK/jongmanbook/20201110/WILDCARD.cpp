#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cache[101][101]; 

string wildCard, fileName;

int matchMemoized(int w, int f) {
        
        int &result = cache[w][f];

        if (result != -1) return result;

        while (f < fileName.size() && w < wildCard.size() && (wildCard[w] == '?' || wildCard[w] == fileName[f])) {
            ++w;
            ++f;
        }

        if (w == wildCard.size()) {
            return result = (f == fileName.size());
        }

        if (wildCard[w] == '*') {
            for (int skip = 0; skip + f <= fileName.size(); skip++){
                    if (matchMemoized(w + 1, f + skip)) {
                            return result = 1;
                    }
            }
        }
        return result = 0;
}

int main(void) {

        int test_case;

        cin >> test_case;

        if (test_case < 1 || test_case>10)
               exit(-1);

        for (int i = 0; i < test_case; i++) {
               vector<string> v;

               cin >> wildCard;

               int fileNum;
               cin >> fileNum;

               if (fileNum < 1 || fileNum > 50)
                       exit(-1);

               for (int j = 0; j < fileNum; j++) {
                       memset(cache, -1, sizeof(cache));

                       cin >> fileName;

                       if (matchMemoized(0, 0) == 1) //조건 성립할 때만 벡터에 삽입
                              v.push_back(fileName);
               }
               sort(v.begin(), v.end()); 

               for (int j = 0; j < v.size(); j++)
                       cout << v[j] << endl;

               cout << endl;

        }
        return 0;

}