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
//394.字符串解码
string stack:: decodeString(string s){
    std::stack<int> nums_stack;        //存数字(倍数)
    std::stack<std::string> al_stack;  //存之前的字符串
    string res = "";                   //当前正在拼接的字符串
    int num = 0;                       //当前的数字

    for(char al:s){
        //1.如果是数字(可能是多位)
        if(isdigit(al))    
        num = num*10 +(al - '0');
        //遇到'['将当前数字与字母压进栈中，然后重置
        else if(al=='['){
            nums_stack.push(num);
            al_stack.push(res);
            //重置
            num = 0;
            res = "";
        }
        //遇到']'开始解码
        else if(al == ']'){
            int k = nums_stack.top();
            nums_stack.pop();

            string prestr = al_stack.top();  //这里是之前的a
            al_stack.pop();

            //把当前字符串重复K次，拼接到之前的字符串
            string temp = "";
            for(int i = 0;i<k;i++){
                temp += res;
            }
            res = prestr + temp;
        }
        //普通字母
        else{
            res += al;
        }
    }
    return res;
}