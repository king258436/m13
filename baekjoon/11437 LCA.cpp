#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
// 트리상 에서 연결된 노드들 만 입력으로 주어지니까 전에 나온 노드번호들을 체크하고 만약에 있으면, 있는게 부모임.
// 은 지랄 김칫국이였고
// 먼저 벡터에 입력을 받고, 부모 노드 걸러주는 작업을 한 후에, lca 찾는 알고리즘으로 찾으면됨.

vector<int> v[50001];
int parent[50001];
bool check[50001];
int depth[50001];

void bfs() {  // bfs로 돌면서 parent 배열을 만들어서 lca 알고리즘을 사용할 준비를 한다.
    queue<int> que;
    que.push(1);
    check[1] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i = 0; i < v[node].size(); i++) {
            if (check[v[node][i]] == false) {
                parent[v[node][i]] = node;
                check[v[node][i]] = true;
                depth[v[node][i]] = depth[node] + 1;
                que.push(v[node][i]);
            }
        }
    }
}

int lca(int a, int b) {
    int high;
    int low;
    if (depth[a] < depth[b]) {
        high = a;
        low = b;
    }
    else {
        high= b;
        low = a;
    }

    while (depth[low]>depth[high]) {
        low= parent[low];
    }
    while(low!=high){
        low = parent[low];
        high = parent[high];
    }
    return high;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }  // 벡터에 연결되어있는 노드들 다 넣음.

    int m;
    cin >> m;
    bfs();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        bfs();
        int result = lca(a, b);
        cout << result << endl;
    }
}