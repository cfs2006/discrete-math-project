#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Dùng pair để lưu {trọng_số, đỉnh}
typedef pair<int, int> pii;

// Hàm thêm cạnh (đồ thị vô hướng nên add cả 2 chiều)
void addEdge(vector<vector<pii>>& adj, int u, int v, int w) {
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
}

void primMST(int V, vector<vector<pii>>& adj, int startNode) {
    // Priority Queue lưu {trọng số, đỉnh}, tự động sort bé nhất lên đầu
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int totalWeight = 0;
    
    // Mảng lưu trọng số nhỏ nhất để đến đỉnh i (khởi tạo vô cực)
    vector<int> key(V + 1, 1e9); 
    
    // Mảng lưu đỉnh cha để truy vết đường đi
    vector<int> parent(V + 1, -1);
    
    // Mảng đánh dấu đã thuộc MST
    vector<bool> inMST(V + 1, false);

    // Khởi tạo đỉnh xuất phát
    pq.push({0, startNode});
    key[startNode] = 0;
    
    // Vector để lưu kết quả các cạnh đã chọn in ra sau cùng
    vector<pair<int, int>> resultEdges;
    vector<int> resultWeights;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Nếu đỉnh u đã xét rồi thì bỏ qua
        if (inMST[u]) continue;

        inMST[u] = true; // Đánh dấu đã đưa vào cây khung

        // Nếu có cha (không phải đỉnh start), lưu lại cạnh vào danh sách kết quả
        if (parent[u] != -1) {
            resultEdges.push_back({parent[u], u});
            resultWeights.push_back(key[u]);
            totalWeight += key[u];
        }

        // Duyệt các đỉnh kề v của u
        for (auto x : adj[u]) {
            int weight = x.first;
            int v = x.second;

            // Nếu v chưa vào MST và trọng số mới nhỏ hơn trọng số cũ
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // --- OUTPUT KẾT QUẢ ---
    cout << "Chieu dai MST: " << totalWeight << endl;
    
    for (size_t i = 0; i < resultEdges.size(); ++i) {
        cout << resultEdges[i].first << " " << resultEdges[i].second 
             << " : " << resultWeights[i] << endl;
    }
    cout << "----------------------------------\n";
}

int main() {
    int V, E, startNode;
    
    cout << "Nhap So Dinh va So Canh: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V + 1);

    cout << "Nhap " << E << " canh (Dinh U - Dinh V - Trong So):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    cout << "Nhap dinh xuat phat: ";
    cin >> startNode;

    primMST(V, adj, startNode);

    return 0;
}