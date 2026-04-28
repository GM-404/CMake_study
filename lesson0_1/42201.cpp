#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 定义依赖关系结构体，增强代码可读性
struct dep_info {
    int pkg1;
    int pkg2;
    int ver;
};

/**
 * 递归函数：深度优先搜索(DFS)检测环
 */
 
bool dfs_loop(int nd, unordered_map<int, vector<int>>& mp, unordered_map<int, int>& st) {
    // 标记当前节点正在访问
    st[nd] = 1;

    if (mp.count(nd)) {
        auto& vec = mp[nd];
        for (int i = 0; i < vec.size(); ++i) {
            int nx = vec[i];

            // 如果子包状态为1，说明在递归路径中再次遇到了它，存在环
            if (st[nx] == 1) return true;
            // 如果子包没访问过，递归检查
            if (st[nx] == 0) {
                if (dfs_loop(nx, mp, st)) return true;
            }
        }
    }

    // 访问结束，标记为安全状态
    st[nd] = 2;
    return false;
}

/**
 * 处理一组依赖关系
 */
bool deal_one() {
    int n;
    // 读取依赖关系的条数
    if (!(cin >> n)) return false;
    // 1. 变量准备
    vector<dep_info> all_dep;               // 存储原始输入数据
    unordered_map<int, vector<int>> g;      // 构建有向图
    unordered_map<int, int> max_ver;       // 统计每个包被要求的最大版本号
    unordered_map<int, int> node_st;       // 节点状态记录

    // 2. 输入与解析
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        // 手动解析 "A,B,V" 格式
        size_t p1 = s.find(',');
        size_t p2 = s.find(',', p1 + 1);

        int a = stoi(s.substr(0, p1));
        int b = stoi(s.substr(p1 + 1, p2 - p1 - 1));
        int v = stoi(s.substr(p2 + 1));

        // 存储原始数据以便最后按顺序输出
        dep_info tmp;
        tmp.pkg1 = a;
        tmp.pkg2 = b;
        tmp.ver = v;
        all_dep.push_back(tmp);

        // 构建图：A 依赖 B
        g[a].push_back(b);

        // 统计 B 包所需的最大版本号
        if (!max_ver.count(b) || v > max_ver[b]) {
            max_ver[b] = v;
        }

        // 初始化状态表中出现的包
        if (!node_st.count(a)) node_st[a] = 0;
        if (!node_st.count(b)) node_st[b] = 0;
    }

    // 3. 循环依赖检测
    bool has_circle = false;
    // 遍历状态表中的所有节点，确保所有连通分量都被检查到
    for (auto& kv : node_st) {
        if (kv.second == 0) {
            if (dfs_loop(kv.first, g, node_st)) {
                has_circle = true;
                break;
            }
        }
    }

    // 4. 输出逻辑
    if (has_circle) {
        cout << "false" << endl;
    } else {
        // 无环，则规整版本并输出
        for (auto& d : all_dep) {
            int x = d.pkg1;
            int y = d.pkg2;
            // 获取被依赖包 b 的全局最大版本号
            int real_v = max_ver[y];
            cout << x << "," << y << "," << real_v << endl;
        }
    }

    return true;
}

int main() {
    // 提升IO性能
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 根据题目描述，每次处理两组或多组直到结束
    while (deal_one()) {}

    return 0;
}