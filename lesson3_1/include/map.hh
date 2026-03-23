#ifndef _MAP_HH_
#define _MAP_HH_

#include <vector>
#include <queue>
#include <string>
// 关于双指针数组的一些集合
class MAP {
public: 
    // 深度优先搜索
    void dfs(std::vector<std::vector<char>>& grid, int i, int j);
    // 200. 岛屿数量
    int numIslands(std::vector<std::vector<char>>& grid);   //深度优先搜索
    int numIslands1(std::vector<std::vector<char>>& grid);  //广度优先搜索
    //207. 课程表
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
    // 994. 腐烂的橘子
    int orangesRotting(std::vector<std::vector<int>>& grid);

};
//208. 实现 Trie (前缀树)
class Trie {
    private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    };
    
   // 插入单词
    void insert(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a'; // 计算字母索引
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true; // 标记单词结尾
    }
    
    // 查找完整单词
    bool search(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return node->isEnd; // 必须是结尾才算找到完整单词
    }
    
    // 查找前缀
    bool startsWith(std::string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return true; // 只要路径走得通，前缀就存在
    }
};
#endif