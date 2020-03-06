#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> input_v;
vector<bool> visit;

void dfs(int n) {
    if(visit[n]) return;
    visit[n] = true;
    cout << n << ' ';
    for(int i = 0; i < input_v[n].size(); i++) {
        dfs(input_v[n][i]);
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visit[n] = true;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << ' ';
        for(int i = 0; i < input_v[temp].size(); i++) {
            int a = input_v[temp][i];
            if(!visit[a]) {
                q.push(a); 
                visit[a] = true;
            }
        }
    }
}


int main() {
    int N, M, V;
    cin >> N >> M >> V;

    visit.assign(N+1, false);

    input_v.assign(N+1, vector<int>());

    // for(int i = 1; i < visit.size(); i++) {
    //     cout << visit[i] << ' ';
    // }
    // cout << '\n';
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        input_v[a].push_back(b);
        input_v[b].push_back(a);
    }

    // cout << "\n================\n";
    // for(int i = 1; i < input_v.size(); i++) {
    //     for(int j = 0; j < input_v[i].size(); j++) {
    //         cout << input_v[i][j] << ' ';
    //     }
    //     cout << '\n';
        
    // }

    dfs(V);
    cout << '\n';
    visit.assign(N+1, false);
    bfs(V);



    return 0;
}