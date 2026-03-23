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
//207. 课程表
bool MAP::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites){
    // 1. 初始化入度表和邻接表
    std::vector<int> indegree(numCourses, 0);
    std::vector<std::vector<int>> adj(numCourses);
    
    // 2. 建图：填充入度表和邻接表
    for (auto& cp : prerequisites) {
        // cp = [想要修的课, 预修课]
        // 即：预修课 -> 想要修的课
        adj[cp[1]].push_back(cp[0]);
        indegree[cp[0]]++;
        }
    // 3. 将所有入度为 0 的课（没有预修课的课）放入队列
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

    // 4. 开始 BFS 拓扑排序
    int count = 0; // 记录修完的课程总数
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++; // 修完一门

        // 遍历这门课解锁的所有后续课程
        for (int next : adj[curr]) {
            indegree[next]--; // 后续课程的预修要求少了一个
            if (indegree[next] == 0) {
                q.push(next); // 如果所有预修课都上完了，入队
            }
        }
    }

    // 5. 如果修完的课等于总课数，说明没有环，可以完成
    return count == numCourses;
}
//994. 腐烂的橘子
int orangesRotting(std::vector<std::vector<int>>& grid){
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int fresh_count = 0; // 新鲜橘子计数器
    int res = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
            else if (grid[i][j] == 1) fresh_count++;
        }
    }
    if (fresh_count == 0) return 0; // 如果本身就没有新鲜橘子，直接收工
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int size = q.size();
        res++;
        for (int i = 0; i < size; i++) {
            auto [curr_i, curr_j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = curr_i + dx[k];
                int nj = curr_j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    fresh_count--; // 被传染一个，少一个
                }
            }
        }
    }
    // //看还有没有孤立的橘子
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (grid[i][j] == 1) {
    //             return -1;
    //         }
    //     }
    // }
    return fresh_count == 0 ? res-1 : -1;
}

