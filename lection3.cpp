/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned. */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    static int myAtoi(string str) {
        int64_t Output;
        int i = 0;
        
        while (i != str.size() && str[i] == ' ') {
            ++i;
        }
        
        if (!(str[i] == '-' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')) {
            return 0;
        }
        
        int j = i + 1;
        
        while (str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9') {
            ++j;
        }
        
        
        if (str[i] == '-') {
                ++i;
            if (j - i > 10) {
                return -2147483648;
            }
            if (str[i] == '0') {
                return 0;
            }
            while (i != j) {
                Output += (str[i] - '0')*(pow(10, j - i - 1));
                ++i;
            }
            Output *= -1;
            if (Output < -2147483648) {
                return -2147483648;
            } 
            return Output;
        }
        
        
        if (j - i > 10) {
            return 2147483647;
        }
        
        while (i != j) {
            Output += (str[i] - '0')*(pow(10, j - i - 1));
            ++i;
        }
        if (Output > 2147483647) {
            return 2147483647;
        }
        return Output;        
    }
};

int main() {
    string a_ = "-42";
    string b_ = " -42";
    string c_ = "  -42";
    int a = Solution::myAtoi(a_);
    int b = Solution::myAtoi(b_);
    int c = Solution::myAtoi(c_);
    cout << a << " " << b << " " << c << endl;

}
