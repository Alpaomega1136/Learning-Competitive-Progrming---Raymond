#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s_l, s_r;
int memo[10][2][2];

int solve_recursive(int pos, bool tight_l, bool tight_r) {
    if (pos == s_l.length()) {
        return 0;
    }

    if (memo[pos][tight_l][tight_r] != -1) {
        return memo[pos][tight_l][tight_r];
    }

    int min_score = 1e9;
    int start_digit = tight_l ? (s_l[pos] - '0') : 0;
    int end_digit = tight_r ? (s_r[pos] - '0') : 9;

    for (int digit = start_digit; digit <= end_digit; ++digit) {
        int current_score = 0;
        if (digit == (s_l[pos] - '0')) current_score++;
        if (digit == (s_r[pos] - '0')) current_score++;

        bool new_tight_l = tight_l && (digit == start_digit);
        bool new_tight_r = tight_r && (digit == end_digit);

        int future_score = solve_recursive(pos + 1, new_tight_l, new_tight_r);
        min_score = min(min_score, current_score + future_score);
    }

    return memo[pos][tight_l][tight_r] = min_score;
}

int calculate_min_score(long long l, long long r) {
    if (l == r) {
        return to_string(l).length() * 2;
    }

    s_l = to_string(l);
    s_r = to_string(r);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                memo[i][j][k] = -1;
            }
        }
    }
    
    return solve_recursive(0, true, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<long long, long long>> test_cases = {
        {199, 201},
        {899, 999},
        {1990, 2001},
        {900990999, 900991010}
    };

    cout << "Template Referensi: Memoization pada Digit DP\n";
    cout << "---------------------------------------------\n";

    for (const auto& test : test_cases) {
        long long l = test.first;
        long long r = test.second;
        int result = calculate_min_score(l, r);
        cout << "Input: " << l << " " << r << " -> Hasil: " << result << endl;
    }

    return 0;
}
