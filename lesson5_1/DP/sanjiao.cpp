#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
int H;
int g[N][N];
int mem[N][N];

int dfs(int x,int y){
    //终止条件
    if(x>H||y>H){
        return 0;
    }
    if(mem[x][y] != -1){
        return mem[x][y];
    }
    int sum;
    sum =  max(dfs(x+1,y),dfs(x+1,y+1)) + g[x][y];
    mem[x][y] = sum;
    return sum;

}

int main(){
    
    memset(mem, -1, sizeof(mem));
    //接收多少行
    cin >> H;

    //输入金字塔
    for(int i = 1; i<= H;i++){
        for(int j = 1;j<=i;j++){
            cin>>g[i][j];
        }
    }
    int res = dfs(1,1);

    cout<< res <<endl;


    return 0;
}

///

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
int H;
int g[N][N];
int mem[N][N];

int dfs(int x,int y){
    //终止条件
    if(x>H||y>H){
        return 0;
    }
    if(mem[x][y] != -1){
        return mem[x][y];
    }
    int sum;
    sum =  max(dfs(x+1,y),dfs(x+1,y+1)) + g[x][y];
    mem[x][y] = sum;
    return sum;

}

int main(){
    
    //memset(mem, -1, sizeof(mem));
    //接收多少行
    cin >> H;

    //输入金字塔
    for(int i = 1; i<= H;i++){
        for(int j = 1;j<=i;j++){
            cin>>g[i][j];
        }
    }
    //int res = dfs(1,1);
    //cout<< res <<endl;
    for (int i = n;i>=1;i--){
        for(int j = 1; j<= n; j++){
            mem[i][j] = max(f[i+1][j],f[i+1][j+1]) + men[i][j];
        }
    }


    return 0;
}