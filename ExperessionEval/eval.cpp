#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <stack>
#define MAX 100

using namespace std;



int isp(char c){
    if(c == '#') return 0;
    else if(c == '(') return 1;
    else if(c == '+' || c == '-') return 2;
    else if(c == '*' || c == '/') return 3;
    else if(c == ')') return 4;
    else {
        printf("Unknown operator : %c\n",c);
        exit(1);
    }
    return 0;
}

int icp(char c){
    if(c == '#') return 0;
    else if(c == ')') return 1;
    else if(c == '+' || c == '-') return 2;
    else if(c == '*' || c == '/') return 3;
    else if(c == '(') return 4;
    else {
        printf("Unknown operator : %c\n",c);
        exit(1);
    }
    return 0;
}

char* convert(char *str){
    int pos = 0;
    char *postfix_expr = new char[MAX];
    stack<char> st;
    st.push('#');
    
    for(int i = 0; i < strlen(str); i++){
        char c = str[i];
        if(isdigit(c)) 
            postfix_expr[pos++] = c;
        else{
            for(;!st.empty() && icp(c) <= isp(st.top()); st.pop())
                if(st.top() != '(' && st.top() != ')' && st.top() != '#')
                    postfix_expr[pos++] = st.top();
            st.push(c);
        }
    }
    
    return postfix_expr;
}

int postfix_eval(char *expr){
    stack<int> op_st;
    for(; *expr != '#';){
        if(isdigit(*expr)){
            char buff[100];
            for(int i = 0; i < 100; i++)
                if(*expr == ' '){
                    buff[i] = '\0';
                    break;
                }else
                    buff[i] = *expr++;
            op_st.push(atoi(buff));
        }
        else if(*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/'){
            int oper = *expr++;
            int op1 = op_st.top(); op_st.pop();
            int op2 = op_st.top(); op_st.pop();
            switch(oper){
                case '+':
                    op_st.push(op1 + op2);
                    break;
                case '-':
                    op_st.push(op1 - op2);
                    break;
                case '*':
                    op_st.push(op1 * op2);
                    break;
                case '/':
                    op_st.push(op1 / op2);
                    break;
                default:
                    break;
            }    
        }
        else
            expr++;
    }
    
    return op_st.top();
}

int main(){
    char *postfix_expr = "1 2 + #";
    //char *infix_expr = "1+2#";
    char *s = "1+2*(3-4)-5/6#";
    printf("%s\n",convert(s));
    printf("%d\n",postfix_eval(postfix_expr));
    return 0;
}