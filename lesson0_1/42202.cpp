#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*首先，明确问题的核心约束和目标：

动作受限：由于 PCB 布线规定只能向下和向右移动，这实际上将问题从通用的图搜索简化为了一个典型的有向无环图（DAG）。

目标函数：我们寻找的不是最短路径，而是最少的转弯次数。这意味着我们不仅要记录到达某个位置的代价，还要关注进入该位置的方向。

核心算法：状态拆分的动态规划 (DP)
为了解决转弯判定的问题，我采用了状态拆分的动态规划方法：
状态定义：我定义了一个三维数组 dp[i][j][dir]：
dp[i][j][0]：表示到达位置 $(i, j)$ 且最后一步是向下移动的最少转弯数。
dp[i][j][1]：表示到达位置 $(i, j)$ 且最后一步是向右移动的最少转弯数。
转移方程：
如果要向下进入 $(i, j)$，它可以从上方格子的“向下状态”转移过来（不转弯），也可以从上方格子的“向右状态”转移过来（转弯一次，代价 +1）。
即：$$dp[i][j][0] = \min(dp[i-1][j][0], dp[i-1][j][1] + 1)$$
同理，如果要向右进入 $(i, j)$：$$dp[i][j][1] = \min(dp[i][j-1][1], dp[i][j-1][0] + 1)$$

初始化与边界：起点 $(0, 0)$ 的初始转弯数为 0，并设置障碍物（非 0 节点）不可通行。
*/


// 定义一个很大的常数代表不可达（无穷大）
const int INF = 1e9;

/**
 * 核心算法函数：计算从起点到终点的最少转弯次数
 * * @param rows   矩阵的行数
 * @param cols   矩阵的列数
 * @param grid   二维矩阵，0表示可通行，非0表示障碍物
 * @return int   返回最少转弯次数，如果不可达则返回 -1
 */
int get_min_turn(int rows, int cols, const vector<vector<int> >& grid) {
    // 拦截特殊情况：起点或终点本身不可通行
    if (grid[0][0] != 0 || grid[rows - 1][cols - 1] != 0) {
        return -1;
    }

    // dp[i][j][0] 表示到达 (i,j) 且最后动作是【向下移动】的最少转弯数
    // dp[i][j][1] 表示到达 (i,j) 且最后动作是【向右移动】的最少转弯数
    vector<vector<vector<int> > > dp(rows, vector<vector<int> >(cols, vector<int>(2, INF)));

    // 初始化起点，在起点时还没有发生任何移动，转弯数为 0
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    // 动态规划过程
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 如果当前节点是障碍物，不可通行，直接跳过
            if (grid[i][j] != 0) {
                continue;
            }

            // 情况 A：计算从上方格子向下走进入 (i, j) 的最少转弯数
            if (i > 0 && grid[i - 1][j] == 0) {
                int no_turn = dp[i - 1][j][0];         // 保持原方向（向下）
                int need_turn = dp[i - 1][j][1] + 1;   // 改变方向（从右转为下）
                dp[i][j][0] = min(no_turn, need_turn);
            }

            // 情况 B：计算从左侧格子向右走进入 (i, j) 的最少转弯数
            if (j > 0 && grid[i][j - 1] == 0) {
                int no_turn = dp[i][j - 1][1];         // 保持原方向（向右）
                int need_turn = dp[i][j - 1][0] + 1;   // 改变方向（从下转为右）
                dp[i][j][1] = min(no_turn, need_turn);
            }
        }
    }

    // 获取到达终点的最少转弯次数（向下到达和向右到达两者取较小值）
    int res = min(dp[rows - 1][cols - 1][0], dp[rows - 1][cols - 1][1]);

    // 如果最小值仍然是无穷大，说明没有任何通路可以到达终点
    if (res >= INF) {
        return -1;
    } 
    
    return res;
}

int main() {
    // 优化输入输出流的性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    // 读取行数和列数
    if (!(cin >> m >> n)) {
        return 0;
    }

    // 1. 检查边界值：如果超出 0 < m, n <= 100 的范围，直接输出 -1
    if (m <= 0 || m > 100 || n <= 0 || n > 100) {
        cout << -1 << "\n";
        return 0;
    }

    // 2. 初始化矩阵并读取 PCB 布局数据
    vector<vector<int> > pcb(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pcb[i][j];
        }
    }

    // 3. 调用单独封装的核心函数计算结果
    int ans = get_min_turn(m, n, pcb);

    // 4. 输出最终结果
    cout << ans << "\n";

    return 0;
}