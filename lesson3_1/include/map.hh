#ifndef _MAP_HH_
#define _MAP_HH_

#include <vector>
#include <queue>
// 关于双指针数组的一些集合
class MAP {
public: 
    // 深度优先搜索
    void dfs(std::vector<std::vector<char>>& grid, int i, int j);
    // 200. 岛屿数量
    int numIslands(std::vector<std::vector<char>>& grid);   //深度优先搜索
    int numIslands1(std::vector<std::vector<char>>& grid);  //广度优先搜索
};

#endif