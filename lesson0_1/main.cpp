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
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
} p[2005];  // 全局数组，更快

ll d[2005]; // 存储距离平方

// 距离平方（避免浮点）
inline ll dist2(const Point& a, const Point& b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> p[i].x >> p[i].y;
        }

        for (int i = 0; i < n; ++i) {
            // 预计算 i 到所有点的距离
            for (int k = 0; k < n; ++k) {
                d[k] = dist2(p[i], p[k]);
            }

            // 排序，用于二分快速统计
            vector<ll> sorted_d(d, d + n);
            sort(sorted_d.begin(), sorted_d.end());

            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    cout << "0 ";
                    continue;
                }

                // 二分查找 <= d[j] 的数量
                int cnt = upper_bound(sorted_d.begin(), sorted_d.end(), d[j]) - sorted_d.begin();
                cnt -= 2; // 去掉 i 和 j 自身

                cout << cnt << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}