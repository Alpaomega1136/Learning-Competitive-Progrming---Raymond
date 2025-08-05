// Link : https://vjudge.net/contest/733687#problem/F

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long totalBeads;
    int numOperations;
    cin >> totalBeads >> numOperations;

    set<long long> segmentStarts;

    segmentStarts.insert(1);
    segmentStarts.insert(totalBeads + 1);

    for (int op_idx = 0; op_idx < numOperations; op_idx++) {
        char operationType;
        long long beadIndex;
        cin >> operationType >> beadIndex;

        if (operationType == 'R') {
            segmentStarts.insert(beadIndex + 1);
        } else if (operationType == 'Q') {
            auto nextSegmentStartIt = segmentStarts.upper_bound(beadIndex);
            auto currentSegmentStartIt = prev(nextSegmentStartIt);

            long long currentSegmentStart = *currentSegmentStartIt;
            long long nextSegmentStart = *nextSegmentStartIt;
            
            long long currentSegmentEnd = nextSegmentStart - 1;

            cout << currentSegmentEnd - currentSegmentStart + 1 << "\n";
        }
    }

    return 0;
}
