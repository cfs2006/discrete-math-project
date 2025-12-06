#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // Để dùng hàm sort

using namespace std;

// Danh sách kề (Đỉnh kề, Trọng số)
vector<vector<pair<int, int>>> adj; 
vector<bool> visited; // Mảng đánh dấu đỉnh đã thăm
vector<int> traversal_sequence; // Dãy đỉnh được duyệt

// Thuật toán DFS (Đệ quy)
void dfs(int u) {
    visited[u] = true; // Đánh dấu u đã được thăm
    traversal_sequence.push_back(u); // Thêm u vào chuỗi kết quả

    // Duyệt qua tất cả các đỉnh kề (neighbor, weight) của u
    for (const auto& edge : adj[u]) {
        int v = edge.first; // Lấy đỉnh kề (v)
        // int w = edge.second; // Trọng số (Bỏ qua trong DFS)
        
        if (!visited[v]) {
            // Nếu v chưa được thăm, gọi đệ quy DFS(v)
            dfs(v);
        }
    }
}

void read_input() {
    int n;
    cout << "Nhap so dinh (N): ";
    cin >> n;
    cin.ignore(); 

    // Khởi tạo các cấu trúc dữ liệu
    adj.resize(n + 1); // Đặt kích thước từ 1 đến N
    visited.resize(n + 1, false); // Tất cả đều chưa được thăm

    cout << "Nhap danh sach ke (Format: Dinh Goc Ke1 TrongSo1 Ke2 TrongSo2...):\n";
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        if (line.empty()) continue; 

        stringstream ss(line);
        int u, v, w;
        
        ss >> u; // Đỉnh gốc
        
        // Đọc liên tiếp các cặp (đỉnh kề - trọng số)
        while (ss >> v >> w) {
            // Thêm cạnh vào danh sách kề (Chỉ cần thêm một chiều vì input đã là danh sách kề của từng đỉnh)
            adj[u].push_back({v, w});
        }
    }

    // Quan trọng: Sắp xếp danh sách kề theo ID đỉnh kề
    // (Đảm bảo DFS luôn ưu tiên đỉnh có ID nhỏ nhất, giúp output đồng nhất)
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
}

int main() {
    read_input();
    
    int start_node;
    cout << "Nhap dinh bat dau duyet DFS: ";
    cin >> start_node;

    cout << "\n--- CHUOI DINH DUYET THEO DFS ---\n";
    if (start_node >= 1 && start_node < adj.size()) {
        dfs(start_node);
        
        for (size_t i = 0; i < traversal_sequence.size(); ++i) {
            cout << traversal_sequence[i];
            if (i < traversal_sequence.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "Loi: Dinh bat dau khong hop le.\n";
    }

    return 0;
}