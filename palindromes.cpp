#include <iostream>
#include <vector>

using namespace std;

bool isEven(int num) {
    if (num % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void printPalindrome(const vector<int>& palindrome) {
    const char letters[] = { 'a', 'b', 'c' };
    for (int digit : palindrome) {
        if (digit < 10) {
            cout << digit;
        }
        else {
            cout << letters[digit - 10];
        }
    }
}

void generatePalindromes(vector<int>& palindrome, int left, int right, int n) {
    if (left > right) {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num = num * 13 + palindrome[i];
        }
        if (isEven(num)) {
            printPalindrome(palindrome);
        }
    }
    else {
        for (int start_digit = 0; start_digit < 13; ++start_digit) {
            palindrome[left] = palindrome[right] = start_digit;
            generatePalindromes(palindrome, left + 1, right - 1, n);
        }
    }
}

int main() {
    int lines;
    cin >> lines;

    while (lines > 0) {
        int n;
        cin >> n;
        if (n < 1 || n > 10) {
            return 1;
        }
        else {
            vector<int> palindrome(n);
            generatePalindromes(palindrome, 0, n - 1, n);
            cout << endl;
        }
        lines--;
    }
    return 0;
}
