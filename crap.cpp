//
// Created by misha on 06/07/2020.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_1 {
public:

    static string longestCommonPrefix(const vector<string>& strs) {

        int i = 0;
        int min = 4294967295;
        while (i != strs.size()) {
            if (min > strs[i].size())
                min = strs[i].size();
            ++i;
        }
        i = 0;
        string www = "";
        int j = 0;
        while (i != min) {
            while (strs[j][i] == strs[j+1][i] && j != strs.size() - 1) {
                ++j;
            }
            if (j == strs.size() - 1 && strs[j-1][i] == strs[j][i]) {
                www.push_back(strs[j][i]);
                j = 0;
                ++i;
                continue;
            }
            break;
        }
        return www;
    }
};

int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    for (int i = 0; i != haystack.size(); ++i) {
        if (needle[0] == haystack[i]) {
            const int y = i++;
            int j = 1;
            while (j != needle.size() && i != haystack.size()) {
                if (needle[j] == haystack[i]) {
                    ++i;
                    ++j;
                    continue;
                }
                return -1;
            }
            if ((j != needle.size() && i == haystack.size())) {
                return -1;
            } else {
                return y;
            }
        }
    }
    return -1;
}

int sum (int i, const int j, const vector<int>& nums) {
    int sum = 0;
    while (i <= j) {
        sum += nums[i];
        ++i;
    }
    return sum;
}
int maxSubArray(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int maxsum = std::numeric_limits<int>::min();
    while (i != nums.size()) {
        j = i;
        while (j < nums.size()) {
            int fuck = sum(i, j, nums);
            if (fuck > maxsum) {
                maxsum = fuck;
            } else {
                ++j;
                while (j < nums.size()) {
                    if (nums[j] <= 0) {
                        continue;
                    } else {
                        break;
                    }
                    ++j;
                }
                continue;
            }
            ++j;
        }
        ++i;
    }
    return maxsum;
}

    string addBinary(string a, string b) {
        string Output;
        int i = 0;
        int balance = 0;
        while (i <= a.size() && i <= b.size()) {
            if (a[a.size() - i] == '1' && b[b.size() - i] == '1' && balance == 1) {
                Output.insert(0, std::string("1"));
                ++i;
                continue;
            }
            if (a[a.size() - i] == '1' && b[b.size() - i] == '1' && balance == 0) {
                Output.insert(0, std::string("0"));
                balance = 1;
                ++i;
                continue;
            }
            if (((a[a.size() - i] == '1' && b[b.size() - i] == '0') || (a[a.size() - i] == '0' && b[b.size() - i] == '1')) && balance == 1) {
                Output.insert(0, std::string("0"));
                ++i;
                continue;
            }
            if (((a[a.size() - i] == '1' && b[b.size() - i] == '0') || (a[a.size() - i] == '0' && b[b.size() - i] == '1')) && balance == 0) {
                Output.insert(0, std::string("1"));
                ++i;
                continue;
            }
            if (a[a.size() - i] == '0' && b[b.size() - i] == '0' && balance == 1) {
                Output.insert(0, std::string("1"));
                balance = 0;
                ++i;
                continue;
            }
            if (a[a.size() - i] == '0' && b[b.size() - i] == '0' && balance == 0) {
                Output.insert(0, std::string("0"));
                ++i;
                continue;
            }
            ++i;
        }
        if(i > a.size() && i > b.size()) {
            return Output;
        }
        if(i > a.size()) {
            while (i <= b.size()) {
                if (b[b.size() - i] == '1' && balance == 1) {
                    Output.insert(0, std::string("0"));
                    ++i;
                    continue;
                }
                if (b[b.size() - i] == '1' && balance == 0) {
                    Output.insert(0, std::string("1"));
                    ++i;
                    continue;
                }
                if (b[b.size() - i] == '0' && balance == 1) {
                    Output.insert(1, std::string("0"));
                    ++i;
                    continue;
                }
                if (b[b.size() - i] == '0' && balance == 0) {
                    Output.insert(0, std::string("0"));
                    ++i;
                    continue;
                }
                ++i;
            }
        }
        if(i > b.size()) {
            while (i <= a.size()) {
                if (a[a.size() - i] == '1' && balance == 1) {
                    Output.insert(0, std::string("0"));
                    ++i;
                    continue;
                }
                if (a[a.size() - i] == '1' && balance == 0) {
                    Output.insert(0, std::string("1"));
                    ++i;
                    continue;
                }
                if (a[a.size() - i] == '0' && balance == 1) {
                    Output.insert(1, std::string("0"));
                    ++i;
                    continue;
                }
                if (a[a.size() - i] == '0' && balance == 0) {
                    Output.insert(0, std::string("0"));
                    ++i;
                    continue;
                }
                ++i;
            }
        }
        return Output;
    }
int main() {
    string a = "111";
    string b = "11";
    cout << addBinary(a, b);
}