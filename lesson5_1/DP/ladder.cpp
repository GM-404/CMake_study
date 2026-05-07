#include <iostream>

using namespace std;

/*
* 暴力存储
*/
int dfs(int n){
    //终止条件
    static int sum = 0; 

    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }
    //没到底，进行递归
    else{
        sum = dfs(n-1)+dfs(n-2);
    }
    return sum;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    //存储阶梯数
    int n;
    cin>> n;
    //进行递归
    cout << dfs(n) << endl;

    return 0;
}
/*
* 加上记忆存储 记忆化搜索 = 暴力dfs + 记录答案
*/
#include <iostream>
#include <vector>

using namespace std;

const int N =10086;
vector<long long> mem(N,-1);

int dfs(int n){
    //终止条件
    //记忆存储，如果递归过就不用递归了
    if(mem[n]!=-1){
        return mem[n];
    }
    if(n == 1){
        mem[n] = 1;
    }else if(n == 2){
        mem[n] = 2;
    }
    //没到底，进行递归
    else{
        mem[n] = dfs(n-1)+dfs(n-2);
    }
    return mem[n];
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    //存储阶梯数
    int n;
    cin>> n;
    //进行递归
    cout << dfs(n) << endl;

    return 0;
}
/*
* DP  递推的公式 = dfs 向下递推的公式
递推的数组初始值 = 递归的边界
*/
#include <iostream>
#include <vector>

using namespace std;
vector<long long> f(N,-1);
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    //存储阶梯数
    int n;
    cin>> n;
    //进行递归
    f[1] = 1; 
    f[2] = 2;

    for(int i = 3; i<= n;i++){
        f[i] = f[i-1]+f[i-1];   //这个递推公式也就是dfs向下递归的公式
    }
    cout << f[n] << endl;

    return 0;
}
//=======================================================================================================================
//江洋大盗
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10086;

int monery[N];
int deal(int T,std::vector<vector<int>> n, int x){
    //终止条件
    if(x>n){
        return 0;
    }
    else{
        return max(deal(T,n,x+1),deal(T,n,x+2)+n[T][x]);
    }
    
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    //输入T组数据
    int T; 
    cin>>T;
    std::vector<vector<int>> n;

    //记录数据
    for(int i = 1; i <= T; i++){
        //每一行有n个数
        cin n;
        for(int j = 1; j<=n;j++){
            cin >> n[i][j];
        }
    }
    int x = 1;  //当前正在洗劫第X家店
    // 循环处理
    while(T--){
        
        //处理第T行数组
        monery[T] = deal(T,n,x);
    }
    for(int i = 0,i<T,i++){
        cout<<monery[i]<<endl;
    }
    


    return 0;
}