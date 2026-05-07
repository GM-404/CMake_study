#include <iostream>
#include <vector>
#include <cstring>
const int nums = 1010;
int N,V;
int v[nums];
int w[nums];
int mem[nums][nums];

using namespace std;

int dfs(int x,int cv){
    //终止条件
    if(x == N||cv<0){
        return 0;
    }
    if (mem[x][cv] != -1) return mem[x][cv];

    int res = 0;

    //如果可以装下
    if(v[x] <= cv){
        res =  max(dfs(x+1,cv),dfs(x+1,cv-v[x]) +w[x]);
        mem[x][cv] = res;
        return res;
    }
    else{
        res = dfs(x+1,cv);
        mem[x][cv] = res;
        return res;
    }
}
int main(){

    cin >> N >> V;
    memset(mem,-1,sizeof(mem));

    for(int i = 0;i<N;i++){
        cin >> v[i] >>w[i];
    }
    
    int res = dfs(0,V);
    
    cout << res<< endl;
    return 0;
}

