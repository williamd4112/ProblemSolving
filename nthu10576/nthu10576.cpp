#include <cstdio>

using namespace std;

const int MAX_N = 1000005;

typedef struct Node {
    int val;
    struct Node *last;
    struct Node *next;
}Node;

Node pool[MAX_N];

void print(Node *begin){
    for(Node *root = begin; root != NULL; root = root->next){
        if(root != begin) 
            putchar(' ');
        printf("%d",root->val);
    }
    putchar('\n');
}

int main(void){
    
    int n;
    scanf("%d",&n);
    
    pool[1].val = 1, pool[1].last = NULL, pool[1].next = &pool[2];
    for(int i = 2; i < n; i++)
        pool[i].val = i, pool[i].last = &pool[i - 1], pool[i].next = &pool[i + 1];
    pool[n].val = n, pool[n].last = &pool[n - 1], pool[n].next = NULL;
    
    Node *begin = &pool[1];    
    char str[10];
    while(scanf("%s",str), str[0] != 'E'){
        int a, b;
        scanf("%d%d", &a, &b);
        
        if(pool[a].next != &pool[b]){
            Node *move_head = begin;
            Node *move_tail = &pool[a];
            
            Node *append_left = pool[b].last;
            Node *append_right = &pool[b];
            
            Node *new_begin = pool[a].next;
            
            append_left->next = move_head;
            move_head->last = append_left;
            
            move_tail->next = append_right;
            append_right->last = move_tail;
            
            begin = new_begin;
            begin->last = NULL;
        }
    }
    print(begin);
    
    return 0;
}