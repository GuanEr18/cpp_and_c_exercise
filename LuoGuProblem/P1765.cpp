#include <iostream>
#include <vector>
#include <array>
#include <utility>
using namespace std;
int main () {
    array<pair<char, int>, 32> arrv = {
        std::pair{'a',1},{'b',2},{'c',3},
        {'d',1},{'e',2},{'f',3},
        {'g',1},{'h',2},{'i',3},
        {'j',1},{'k',2},{'l',3},
        {'m',1},{'n',2},{'o',3},
        {'p',1},{'q',2},{'r',3},{'s',4},
        {'t',1},{'u',2},{'v',3},
        {'w',1},{'x',2},{'y',3},{'z',4},
        {' ',1},{'*',1},{'#',1}
    };
    string str;
    int count = 0;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < arrv.size(); j++) {
            if (str[i] == arrv[j].first) {
                count += arrv[j].second;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}