#ifndef _STACK_HH_
#define _STACK_HH_



class stack{ 
public:
    //20.有效的括号
    bool isValid(string s);
    //394.字符串解码
    std::string decodeString(string s);
    //739.每日温度
    std::vector<int>dailyTemperatures(std::vector<int>& temperatures);
    
};

//155.最小栈
class MinStack{
private:
    std::stack<int> st;     //正常存数据
    std::stack<int> minSt;  //专门存最小值
public:
    MinStack(){
    }

    void push(int val){
        st.push(val);
        //最小栈为空，或者当前值更小，就压入
        if(minSt.empty()||val<=minSt.top()){
            minSt.push(val);
        }
    }
    void pop(){
        //如果栈顶就是最小值，最小栈也要弹出来
        if(st.top()==minSt.top()){
            minSt.pop();
        }
        st.pop();

    }
    int top(){
        return st.top();
    }
    int getMin(){
        return minSt.top();
    }

};
#endif