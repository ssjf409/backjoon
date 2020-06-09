#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

// int arr[9];
vector<int> arr;
vector<int> input;
vector<bool> visited;
set<vector<int>> s;


void printAllPath(int index, int num) {
    if(num == M) {
        // for(int i = 0; i < M; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        if(s.find(arr) == s.end()) {
            s.insert(arr);
        }
        return;
    }
    if(index == N) return;

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        arr[index] = input[i];
        visited[i] = true;
        printAllPath(index + 1, num + 1);
        visited[i] = false;
    }
}

bool compare(const int& a, const int& b) {
    return a < b;
}

int main() {
    cin >> N >> M;
    arr.assign(M, 0);
    input.assign(N, 0);
    visited.assign(N, false);

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end(), compare);

    printAllPath(0, 0);

    for(const auto& el : s) {
        for(int i = 0; i < el.size(); i++) {
            cout << el[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}