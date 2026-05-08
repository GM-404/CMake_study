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
