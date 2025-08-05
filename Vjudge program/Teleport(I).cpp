#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <string>

using namespace std;

using State = pair<int, pair<int, int>>;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    map<pair<int, int>, pair<int, int>> teleporters;
    for(int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        teleporters[{x1 - 1, y1 - 1}] = {x2 - 1, y2 - 1};
    }

    vector<vector<int>> distances(N, vector<int>(M, 1e9));
    
    priority_queue<State> pq;

    distances[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int d = -pq.top().first;
        auto [r, c] = pq.top().second;
        pq.pop();

        if (d > distances[r][c]) {
            continue;
        }

        if (teleporters.count({r, c})) {
            auto [dest_r, dest_c] = teleporters[{r, c}];
            
            if (distances[r][c] < distances[dest_r][dest_c]) {
                distances[dest_r][dest_c] = distances[r][c];
                pq.push({-distances[dest_r][dest_c], {dest_r, dest_c}});
            }
        } 
        else {
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] != '#') {
                    if (distances[r][c] + 1 < distances[nr][nc]) {
                        distances[nr][nc] = distances[r][c] + 1;
                        pq.push({-distances[nr][nc], {nr, nc}});
                    }
                }
            }
        }
    }

    cout << distances[N - 1][M - 1] << endl;

    return 0;
}
