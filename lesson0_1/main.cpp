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
#include <vector>

using namespace std;

int M,N;
const int INF = 1e9;

int get_min_turn(vector<vector<int>> map){

    //判断起点终点是否可达
    if(map[0][0]!=0||map[M-1][N-1]!=0)
    {
        return -1;
    }
    //状态转移方程
    //需要一个二维数组，这个二维数组需要存储到达当前节点的最小转弯次数，同时还需要一维来存储到达该节点的时候方向是向左的还是向下的，所以需要一个三维数组
    vector<vector<vector<int>>> dp(M,vector<vector<int>>(N,vector<int>(2,INF)));
    //初始化节点
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(map[i][j]!= 0){
                continue;
            }
            //情况A，走到当前节点，是从上下来的，并且方向向下，这个时候也要分两种情况，上面的格子是向右的还是向下的
            //如果是向右的，走到当前节点需要一次转向，如果是向下的，不需要转向
            //第一行没有上面，并且上面的要是可达的
            if(i>0&&map[i-1][j] == 0){
                //转向
                int turn = dp[i-1][j][1] + 1;
                //不转
                int no_turn = dp[i-1][j][0];
                //当前状态肯定取两者之间小的那一个
                dp[i][j][0] =  min(turn,no_turn);
            }
            //情况B，走到当前节点，是从左面平移来的，并且方向向右，这个时候也要分两种情况，左面的格子是向右的还是向下的
            //如果是向下的，走到当前节点需要一次转向，如果是向右的，不需要转向
            //第一列没有上面，并且左面的要是可达的
            if(j>0&&map[i][j-1] == 0){
                //转向
                int turn = dp[i][j-1][0] + 1;
                //不转
                int no_turn = dp[i][j-1][1];
                //当前状态肯定取两者之间小的那一个
                dp[i][j][1] =  min(turn,no_turn);
            }
        }
    }
    int min_turn = min(dp[M-1][N-1][0],dp[M-1][N-1][1]);
    if(min_turn>=INF){
        return -1;
    }
    return min_turn;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    if(!(cin>>M>>N)){
        return 0;
    }
    //判断是否合规
    if(M<=0||M>100||N<=0||N>100){
        cout<<-1<<endl;
        return 0;
    }
    //存放pcb
    vector<vector<int>> pcb(M,vector<int>(N));
    for(int i = 0; i<M;i++){
        for(int j = 0;j<N;j++){
            cin>>pcb[M][N];
        }
    }
    int res = get_min_turn(pcb);

    cout<<res<<endl;
    return 0;
}
