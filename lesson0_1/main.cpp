// #include <stdio.h>
// #include <string.h>   // C 语言字符串头文件
// #include <stdlib.h>   // malloc / free

// const int   g_A = 10;     // 常量区（只读数据段）
// int         g_B = 20;     // 数据段（已初始化全局）
// static int  g_C = 30;     // 数据段（已初始化静态全局）
// static int  g_D;          // BSS 段（未初始化静态全局）
// int         g_E;          // BSS 段（未初始化全局）
// char        *p1;          // BSS 段（未初始化全局指针）

// int main() {
//     int  local_a = 0;     // 栈区（初始化避免警告）
//     int  local_b = 0;     // 栈区

//     static int  local_c = 1;  // 数据段（已初始化静态局部）
//     static int  local_d;      // BSS 段（未初始化静态局部）

//     const char *p3 = "123456";   // "123456" → 常量区；p3 → 栈区

//     // 堆区分配
//     p1 = (char *)malloc(10);
//     char *p2 = (char *)malloc(20);

//     // 安全判断
//     if (p1 == NULL || p2 == NULL) {
//         printf("malloc failed\n");
//         return -1;
//     }

//     strcpy(p1, "123456");

//     printf("hight address\n");
//     printf("------------栈区------------\n");
//     printf("栈 local_a      addr: %p\n", &local_a);
//     printf("栈 local_b      addr: %p\n", &local_b);

//     printf("------------堆区------------\n");
//     printf("堆 p1 指向地址  addr: %p\n", p1);   // ✔ 打印堆地址
//     printf("堆 p2 指向地址  addr: %p\n", p2);

//     printf("------------BSS段------------\n");
//     printf("BSS g_E         addr: %p\n", &g_E);
//     printf("BSS g_D         addr: %p\n", &g_D);
//     printf("BSS local_d     addr: %p\n", &local_d);
//     printf("BSS p1(指针本身)addr: %p\n", &p1);

//     printf("------------数据段------------\n");
//     printf("数据段 g_B      addr: %p\n", &g_B);
//     printf("数据段 g_C      addr: %p\n", &g_C);
//     printf("数据段 local_c  addr: %p\n", &local_c);

//     printf("------------常量区------------\n");
//     printf("常量区 g_A      addr: %p\n", &g_A);
//     printf("常量区 字符串   addr: %p\n", p3);

//     printf("low address\n");

//     // 释放堆内存
//     free(p1);
//     free(p2);

//     return 0;
// }

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int N =1010;
vector<int> dmg;
vector<int> rew;

int main(){

    string line;
    //输入奥特曼能量
    long long E;
    cin>>E;
    cin.ignore();

    getline(cin,line);
    stringstream line1(line);
    long long tmp;
    while(line1>>tmp){
        dmg.push_back(tmp);
    }

    getline(cin,line);
    stringstream line2(line);
    while(line2>>tmp){
        rew.push_back(tmp);
    }
    //定义DP数组
    int n = dmg.size();
    //dp[i][j] 表示考虑前 i 只怪兽，在击败j 只的情况下，拥有的最大剩余能量。
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
    dp[0][0] = E;
    
    for (int i = 1;i<=n;i++){
        for(int j= 0;j<=i;j++){
            //情况A，不打第i只怪兽，
            //那么打败第j个的状态，由前i-1个怪兽也打败了j个转移过来
            if(dp[i-1][j]!= -1){
                dp[i][j]= dp[i-1][j]; //在第i个的时候打了第j只
            }
            if(j>0&&dp[i-1][j-1]>dmg[i-1]){
                long long energy_after_fight = dp[i - 1][j - 1] - dmg[i - 1] + rew[i - 1];
                dp[i][j] = max(dp[i][j], energy_after_fight);
            }
        }
    }
    // 5. 遍历最后一行 dp[n][j]，找到最大的 j 使得能量不为 -1
    int ans = 0;
    for (int j = n; j >= 0; j--) {
        if (dp[n][j] != -1) {
            ans = j;
            break;
        }
    }
    //int ans = dfs(0,E);
    cout <<ans<<endl;
    return 0;
}