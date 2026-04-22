#include "stack.hh"
#include <stack>

//20 有效的括号
bool stack::isValid(string s){
    
    //栈
    std::stack<char> res;
    for(char c:s){
        //左括号:入栈
        if(c == '('||c == '['||c=='{'){
            res.push(c);
        }
        else{
            //判断是否是空栈
            if(res.empty()){
                return false;
            }
            //不是空栈
            char top = res.top();
            res.pop();

            if((c==')'&& top!='(') || (c==']'&& top!='[')||(c=='}'&& top!='{') ){
                return false;
            }
        }
    }
    return res.empty();
}