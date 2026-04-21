#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Win {
    string name;
    int x, y, w, h, level, id;
};

// 全局状态封装
int SW, SH;
vector<Win> wins;
int gid = 0;

// --- 逻辑辅助函数 ---

bool isCovered(int x1, int y1, int x2, int y2, const Win& b) {
    return x1 >= b.x && y1 >= b.y && x2 <= b.x + b.w && y2 <= b.y + b.h;
}

bool checkVis(const Win& t) {
    // 检查是否在屏幕外
    if (t.x + t.w <= 0 || t.x >= SW || t.y + t.h <= 0 || t.y >= SH) {
        return false;
    }
    
    // 检查是否被更高优先级窗口完全覆盖
    for (const auto& w : wins) {
        if (w.name == t.name) continue;
        bool above = (w.level > t.level) || (w.level == t.level && w.id > t.id);
        if (above) {
            if (isCovered(max(0, t.x), max(0, t.y), min(SW, t.x + t.w), min(SH, t.y + t.h), w)) 
                return false;
        }
    }
    return true;
}

// --- 业务操作函数 ---
// 
bool handleInit() {
    int w, h; 
    cin >> w >> h;
    if (w > 0 && h > 0) { 
        SW = w; 
        SH = h; 
        return true; 
    }
    return false;
}

bool handleCreate() {
    string n; 
    int x, y, w, h, l; 
    cin >> n >> x >> y >> w >> h >> l;
    for (const auto& win : wins){ 
        if (win.name == n) {
        return false;
        }
    }
    if (w > 0 && h > 0) {
        wins.push_back({n, x, y, w, h, l, gid++});
        return true;
    }
    return false;
}

bool handleRemove() {
    string n; 
    cin >> n;
    for (auto it = wins.begin(); it != wins.end(); ++it) {
        if (it->name == n) { 
            wins.erase(it);
            return true; 
        }
    }
    return false;
}

void handleQueryVis() {
    string n; 
    cin >> n;
    bool visible = false;
    for (const auto& win : wins) {
        if (win.name == n) { 
        visible = checkVis(win); 
        break; 
        }
    }
    cout << (visible ? "true" : "false") << endl;
}

void handleQueryAll() {
    int x, y, w, h; 
    cin >> x >> y >> w >> h;
    vector<Win> res;
    for (const auto& win : wins) {
        if (checkVis(win)) {
            bool inter = !(win.x + win.w <= x || win.x >= x + w || win.y + win.h <= y || win.y >= y + h);
            if (inter) res.push_back(win);
        }
    }
    if (res.empty()) cout << "NoVisibleWindow" << endl;
    else {
        sort(res.begin(), res.end(), [](const Win& a, const Win& b) {
            return a.level != b.level ? a.level > b.level : a.name < b.name;
        });
        for (size_t i = 0; i < res.size(); ++i) 
            cout << res[i].name << (i == res.size() - 1 ? "" : ";");
        cout << endl;
    }
}

bool handleTransform(string op) {
    string n; 
    int v1, v2; 
    cin >> n >> v1 >> v2;
    for (auto& win : wins) {
        if (win.name == n) {
            if (op == "resizeWindow" && v1 > 0 && v2 > 0) { win.w = v1; win.h = v2; return true; }
            if (op == "moveWindow") { win.x = v1; win.y = v2; return true; }
        }
    }
    return false;
}

// --- 主循环 ---

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string op;
    while (cin >> op) {
        if (op == "init") cout << (handleInit() ? "true" : "false") << endl;
        else if (op == "createWindow") cout << (handleCreate() ? "true" : "false") << endl;
        else if (op == "removeWindow") cout << (handleRemove() ? "true" : "false") << endl;
        else if (op == "queryVisibility") handleQueryVis();
        else if (op == "queryAllVisibleWindows") handleQueryAll();
        else if (op == "resizeWindow" || op == "moveWindow") cout << (handleTransform(op) ? "true" : "false") << endl;
    }
    return 0;
}