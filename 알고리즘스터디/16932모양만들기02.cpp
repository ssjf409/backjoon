#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

int bfs(int y, int x) {
    if(visited[y][x]) return board[y][x];
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    
    queue<pair<int, int>> path;
    path.push({y, x});

    int cnt = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            if(!board[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
            path.push({ny, nx});
            cnt++;
        }
    }
    
    while(!path.empty()) {
        int cy = path.front().first;
        int cx = path.front().second;
        path.pop();
        board[cy][cx] = cnt;
    }

    return cnt;
}


int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }


    int maxCnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j]) {
                int temp = 1;
                for(int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if(!board[ny][nx]) continue;
                    temp += bfs(i, j);
                }
                if(temp > maxCnt) maxCnt = temp;
            }
        }
    }

    cout << maxCnt;


    return 0;
}