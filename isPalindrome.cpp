#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    string input;
    while (true) {
        cout << "请输入一个字符串（0<n<81），输入'Q'退出：";
        cin >> input;
        if (input == "Q") break;
        if (input.length() == 0 || input.length() >= 81) {
            cout << "输入的字符串长度不符合要求。\n";
            continue;
        }
        if (isPalindrome(input)) {
            cout << "这是一个回文字符串。\n";
        }
        else {
            cout << "这不是一个回文字符串。\n";
        }
    }
    return 0;
}