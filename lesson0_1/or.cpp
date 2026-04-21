#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];   
int init_val[MAXN];
int goal_val[MAXN];
int ans = 0;

/**
 * DFS 遍历树
 * @param u 当前节点
 * @param p 父节点
 * @param level 当前深度（用于区分奇偶层）
 * @param odd_f 奇数层祖先累计翻转次数
 * @param even_f 偶数层祖先累计翻转次数
 */
void dfs(int u, int p, int level, int odd_f, int even_f) {
    int current_f = (level % 2 == 1) ? odd_f : even_f;
    
    // 计算当前节点受到祖先翻转后的实际值
    int real_val = (init_val[u] + current_f) % 2;
    
    // 如果实际值不等于目标值，则必须在此节点操作一次
    if (real_val != goal_val[u]) {
        ans++;
        if (level % 2 == 1) odd_f++;
        else even_f++;
    }
    
    // 递归处理子节点
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, level + 1, odd_f, even_f);
    }
}

int main() {
    // 优化 IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // 读取边信息
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 读取初始值
    for (int i = 1; i <= n; ++i) cin >> init_val[i];
    // 读取目标值
    for (int i = 1; i <= n; ++i) cin >> goal_val[i];

    // 从根节点1开始 DFS，根节点视为第1层（奇数层）
    dfs(1, 0, 1, 0, 0);

    cout << ans << endl;

    return 0;
}