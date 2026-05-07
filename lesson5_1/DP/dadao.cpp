#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


int dfs(vector<int>& nums,int idx,vector<int>& dp){
    //终止条件
    if(idx>= nums.size()){
        return 0;
    }
    if(dp[idx]!= -1){
        return dp[idx];
    }
    int steal = nums[idx] + dfs(nums,idx+2,dp);
    int not_steal = dfs(nums,idx+1,dp);

    return dp[idx] = max(steal,not_steal);
    
}
int rob(vector<int>& nums){
    vector<int> dp(nums.size(),-1);
    return dfs(nums,0,dp);
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    //输入T组数据
    cout<< "输入T组数据"<<endl;
    int T; 
    cin>>T;

    // 循环处理
    while(T--){
        int g;
        cin >> g;
        std::vector<int> nums(g);

        for(int i = 0;i<g;i++){
            cin>>nums[i];
        }

        cout << rob(nums)<<endl;
    }
    return 0;
}
