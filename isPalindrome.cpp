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
        cout << "������һ���ַ�����0<n<81��������'Q'�˳���";
        cin >> input;
        if (input == "Q") break;
        if (input.length() == 0 || input.length() >= 81) {
            cout << "������ַ������Ȳ�����Ҫ��\n";
            continue;
        }
        if (isPalindrome(input)) {
            cout << "����һ�������ַ�����\n";
        }
        else {
            cout << "�ⲻ��һ�������ַ�����\n";
        }
    }
    return 0;
}