// Link : https://vjudge.net/contest/733687#problem/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> matriks(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;

            if (i == 0 && j == 0) {
                matriks[i][j] = x;
            } else if (i == 0) {
                matriks[i][j] = min(matriks[i][j - 1], x);
            } else if (j == 0) {
                matriks[i][j] = min(matriks[i - 1][j], x);
            } else {
                matriks[i][j] = min({matriks[i - 1][j], matriks[i][j - 1], x});
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        cout << matriks[x - 1][y - 1] << "\n";
    }

    return 0;
}
