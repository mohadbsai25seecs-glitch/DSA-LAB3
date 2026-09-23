#include<iostream>
#include <string>
using namespace std;
// boolean function for checking if the string is palindrome//
bool is_Pal(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
//main function
int main() {
    string s;
    while (true) {
        cout << "Enter a string: ";
        getline(cin, s);
        cout << (is_Pal(s) ? "Palindrome" : "Not a palindrome") << "\n\n";
    }
    return 0;
}