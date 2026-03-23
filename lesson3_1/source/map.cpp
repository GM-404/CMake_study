#include "MAP.hh"

// 200. 岛屿数量
// https://leetcode-cn.com/problems/number-of-islands/
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
int MAP::numIslands(std::vector<std::vector<char>>& grid){
    if (grid.empty()) return 0; // 先检查是否为空
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}
// 深度优先搜索 只要附近找到1，就将其置为0，然后继续搜索附近的1
void MAP::dfs(std::vector<std::vector<char>>& grid, int i, int j) { 
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int MAP::numIslands1(std::vector<std::vector<char>>& grid){
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    
    // 方向数组，嵌入式开发中常用的查表法思想
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                // 开始 BFS 扫荡
                std::queue<std::pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0'; // 只要进队，就标记为已访问

                while (!q.empty()) {
                    auto [curr_i, curr_j] = q.front();
                    q.pop();

                    // 探测四个方向
                    for (int k = 0; k < 4; k++) {
                        int ni = curr_i + dx[k];
                        int nj = curr_j + dy[k];

                        // 边界检查 + 岛屿检查
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                            q.push({ni, nj});
                            grid[ni][nj] = '0'; // 关键：入队即沉岛
                        }
                    }
                }
            }
        }
    }
    return count;
}


