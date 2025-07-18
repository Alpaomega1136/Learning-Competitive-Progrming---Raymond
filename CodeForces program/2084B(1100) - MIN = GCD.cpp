#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

long long calculate_vector_gcd(const vector<long long>& vec) {
    if (vec.empty()) {
        return 0; 
    }
    long long result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    struct testcase {
        int size;
        vector<long long> numbers;
        string answer;
    };

    vector<testcase> testcases(t);

    for (int i = 0; i < t; ++i) {
        cin >> testcases[i].size;
        testcases[i].numbers.resize(testcases[i].size);
        for (int j = 0; j < testcases[i].size; ++j) {
            cin >> testcases[i].numbers[j];
        }
    }

    for (int i = 0; i < t; ++i) {
        long long min_val = testcases[i].numbers[0];
        for (size_t j = 1; j < testcases[i].numbers.size(); ++j) {
            if (testcases[i].numbers[j] < min_val) {
                min_val = testcases[i].numbers[j];
            }
        }

        vector<long long> prefix_forced;
        vector<long long> suffix_forced;

        prefix_forced.push_back(min_val);
        bool min_val_placed = false;

        for (long long num : testcases[i].numbers) {
            if (num == min_val && !min_val_placed) {
                min_val_placed = true;
                continue; 
            }
            
            if (num % min_val == 0) {
                suffix_forced.push_back(num);
            } else {
                prefix_forced.push_back(num);
            }
        }

        if (suffix_forced.empty()) {
            testcases[i].answer = "No";
        } else {
            long long final_gcd = calculate_vector_gcd(suffix_forced);
            if (final_gcd == min_val) {
                testcases[i].answer = "Yes";
            } else {
                testcases[i].answer = "No";
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        cout << testcases[i].answer << "\n";
    }

    return 0;
}
