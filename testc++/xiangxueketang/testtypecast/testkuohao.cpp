//
// Created by 王海龙 on 2021/9/29.
// 括号匹配算法
//
#include <iostream>
#include <stack>

using namespace std;

string lefts = "{[(";//
string rights = "}])";

bool check(string, int);

int main() {
    string testStr = "{{brace*&^[square(round)]end}";
    string testStr2 = "{brace*&^[square(round])end}";
    cout << boolalpha << check(testStr, testStr.length()) << endl;
    cout << boolalpha << check(testStr2, testStr2.length()) << endl;
    return 0;
}

bool check(string str, int n) {
    stack<char> s;
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        int indexLeft = -1, indexRight = -1;
        indexLeft = lefts.find(ch);
        indexRight = rights.find(ch);
        if (indexLeft >= 0) {
            s.push(ch);
        } else if (indexRight >= 0) {
            if (!s.empty() && s.top() == lefts[indexRight]) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}
