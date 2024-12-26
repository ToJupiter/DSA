#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const string& seg) {
    return seg.length() <= 3 && (seg.length() == 1 || seg[0] != '0') && stoi(seg) <= 255;
}

int main() {
    string s;
    cin >> s;

    vector<string> result;
    vector<string> segments;
    int n = s.length();

    function<void(int, int)> backtrack = [&](int prev_dot, int dots) {
        int max_pos = min(n - 1, prev_dot + 4);
        for (int curr_dot = prev_dot + 1; curr_dot < max_pos; ++curr_dot) {
            string seg = s.substr(prev_dot + 1, curr_dot - prev_dot);
            if (isValid(seg)) {
                segments.push_back(seg);
                if (dots - 1 == 0) {
                    string last_seg = s.substr(curr_dot + 1);
                    if (isValid(last_seg)) {
                        segments.push_back(last_seg);
                        string ip = segments[0];
                        for (size_t i = 1; i < segments.size(); ++i) {
                            ip += "." + segments[i];
                        }
                        result.push_back(ip);
                        segments.pop_back();
                    }
                } else {
                    backtrack(curr_dot, dots - 1);
                }
                segments.pop_back();
            }
        }
    };

    backtrack(-1, 3);

    for (const string& ip : result) {
        cout << ip << endl;
    }

    return 0;
}