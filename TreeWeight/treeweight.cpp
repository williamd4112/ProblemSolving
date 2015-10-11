#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#define MAXLEN 50

using namespace std;

typedef struct Node{
    int val;
    vector<struct Node*> children;
    vector<struct Node*>::iterator it;

    Node(int val, Node *left, Node *right){
        this->val = val;
        children.push_back(left);
        children.push_back(right);
        it = children.begin();
    }

    void append(Node *node){
        if(node != NULL)
            val += node->val;
        *it++ = node;
    }

}Node;

Node *loadTree(string::iterator expr_it, string::iterator expr_end){
    stack<Node*> st;
    st.push(new Node(0, NULL, NULL));
    for(; expr_it != expr_end;){
        if(*expr_it == '('){
            expr_it++;

            int i;
            char buff[MAXLEN];
            for(i = 0; i < MAXLEN && *expr_it != '(' && *expr_it != ')'; i++)
                buff[i] = *expr_it++;
            buff[i] = '\0';

            if(strlen(buff) < 1)
                st.push(NULL);
            else
                st.push(new Node(atoi(buff), NULL, NULL));
        }
        else if(*expr_it == ')'){
            expr_it++;

            Node *pop_node = st.top(); st.pop();
            Node *top_node = st.top();

            top_node->append(pop_node);
        }
    }

    return st.top()->children[0];
}

void print(Node *node){
    if(node != NULL){
        printf("(%d",node->val);
        print(node->children[0]);
        print(node->children[1]);
        printf(")");
    }else
        printf("()");
}

int main(){
    string expr;
    //freopen("in.txt","r",stdin);
    while(getline(cin, expr) != NULL){
        Node *root = loadTree(expr.begin(), expr.end());
        print(root);
        putchar('\n');
    }

    return 0;
}
