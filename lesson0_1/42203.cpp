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
map<pair<int,long long>,int> mem;
int dfs(int idx,long long nl){
    //终止条件
    if(idx>=dmg.size()){
        return 0;
    }
    if(mem.count({idx, nl})){
        return mem[{idx,nl}];
    }
    //当能量不够或者选择不打的时候
    int res1 = dfs(idx+1,nl);
    //当能量够用的时候
    int res2 =0;
    if(nl>dmg[idx]){
    res2 = 1+ dfs(idx+1,nl - dmg[idx] + rew[idx]);
    }

    return mem[{idx,nl}]= max(res1,res2);
}
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

    int ans = dfs(0,E);

    cout <<ans<<endl;
    return 0;
}

//方法2
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