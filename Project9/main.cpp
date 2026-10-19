#include <iostream>
using namespace std;

int convertToInt(const char s[]) {
    int i = 0;
    int sign = 1;
    int result = 0;

    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (s[i] == '+') {
        i++;
    }

    if (s[i] == '\0') {
        throw "No digits in input!";
    }

    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') {
            throw "Invalid character!";
        }

        int digit = s[i] - '0';

        if (sign == 1) {
            if (result > (2147483647 - digit) / 10) {
                throw "Integer overflow!";
            }
            result = result * 10 + digit;
        }
        else {
            if (result < (-2147483647 - 1 + digit) / 10) {
                throw "Integer overflow!";
            }
            result = result * 10 - digit;
        }

        i++;
    }

    return result;
}

int main() {
    char s[100];

    cout << "Enter a decimal number: ";
    cin >> s;

    try {
        cout << "Result: " << convertToInt(s) << endl;
    }
    catch (const char* error) {
        cout << "Error: " << error << endl;
    }

}