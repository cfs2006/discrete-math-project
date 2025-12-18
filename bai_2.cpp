// THUAT TOAN - DFS - DO THI
#include <iostream>
#include <vector>
#include <cstring>   // memset

using namespace std;

int n, m;
vector<int> adj[500];   // danh sach ke
bool visited[500];

void inp() {
    cout << "Nhap so dinh va so canh (n m): ";
    cin >> n >> m;

    cout << "Nhap danh sach cac canh (x y), moi canh tren 1 dong:\n";
    cout << "(Luu y moi canh chi nhap 1 lan)\n";

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);

        // Bo dong nay neu do thi co huong
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    inp();

    int start;
    cout << "Nhap dinh bat dau duyet DFS: ";
    cin >> start;

    cout << "\n--- THU TU DUYET DFS ---\n";
    dfs(start);

    cout << "\n-----------------------\n";
    return 0;
}