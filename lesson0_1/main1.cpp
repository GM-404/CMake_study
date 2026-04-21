#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //操作数
    int n;
    cin >> n;
    //最大历史记录
    int max_history;
    cin >> max_history;
    //历史记录使用deque实现
    deque<string> history;
    //前进记录使用栈模拟
    vector<string> forward_stack;
    history.push_back("Blank");
    
    string ptr,wangzhan;
    for(int i=0;i<n;i++){
        cin>>ptr;
        //访问新网站，清空前进记录
        if(ptr=="visit"){
            cin>>wangzhan;
            forward_stack.clear();
            history.push_back(wangzhan);
            if(history.size()>max_history){
                history.pop_front();
            }
        }
        //后退
        else if(ptr=="back"){
            if(history.size()>1){
                //将当前页面加入前进栈
                forward_stack.push_back(history.back());
                //将历史记录最后一个页面弹出
                history.pop_back();
            }
        }
        //前进
        else if(ptr == "forward"){
            if(!forward_stack.empty()){
                //将当前页面加入历史记录
                history.push_back(forward_stack.back());
                //将前进栈最后一个页面弹出
                forward_stack.pop_back();
                }
            }
        else if(ptr == "print"){
            //打印当前页面
            cout<<history.back()<<endl;
        }
    }
    return 0;
}