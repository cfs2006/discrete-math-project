#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Thư viện quan trọng để xử lý chuỗi nhập vào

using namespace std;

// Cấu trúc để lưu một cạnh
struct Edge {
    int u, v, w;
};

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    
    // Xóa bộ nhớ đệm bàn phím để chuẩn bị dùng getline
    cin.ignore(); 

    vector<Edge> edgeList;

    cout << "Nhap danh sach ke (Format: Dinh Ke1 TrongSo1 Ke2 TrongSo2 ...):" << endl;
    
    // Vòng lặp đọc từng dòng
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line); // Đọc nguyên 1 dòng nhập vào
        
        if (line.empty()) continue; // Bỏ qua nếu lỡ nhập dòng trống

        stringstream ss(line); // Biến dòng chữ vừa đọc thành 1 luồng dữ liệu
        int u, v, w;
        
        ss >> u; // Số đầu tiên của dòng là Đỉnh gốc

        // Vòng lặp đọc liên tiếp các cặp (đỉnh kề - trọng số) trong dòng đó
        while (ss >> v >> w) {
            // LOGIC QUAN TRỌNG:
            // Vì đồ thị vô hướng, cạnh (1,2) và (2,1) là một.
            // Ta chỉ lưu khi u < v để tránh in trùng lặp 2 lần.
            if (u < v) {
                edgeList.push_back({u, v, w});
            }
        }
    }

    // Xuất kết quả
    cout << "\n-----------------------------\n";
    cout << "KET QUA DANH SACH CANH:" << endl;
    cout << "Dinh1  Dinh2  TrongSo" << endl;
    for (const auto& edge : edgeList) {
        cout << "  " << edge.u << "      " << edge.v << "      " << edge.w << endl;
    }

    return 0;
}