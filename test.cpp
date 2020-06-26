#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, first;
int arr[10000][3];
int cache[10001][3][3];
int path[10001];

int getMinCost(int pos, int previous, int first) {
    // 기저 사례
    if(pos == N) {
        for(int i = 0; i < N; i++) {
            cout << path[i] << ' ';
        }
        cout << endl;

        if(first == path[N - 1]) return INF;
        return 0;
    }

    int& ret = cache[pos][previous][first];
    if(ret != -1) return ret;

    ret = INF;


    for(int i = 0; i < 3; i++) {
        if(pos == 0 || previous != i) {
            path[pos] = i;
            ret = min(ret, getMinCost(pos + 1, (pos == 0) ? first : i, first) + arr[pos][i]);
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    memset(cache, -1, sizeof(cache));

    int ret = INF;
    for(int i = 0; i < 3; i++) {
        ret = min(ret, getMinCost(0, 0, i));
    }
    cout << ret;
    

    return 0;
}