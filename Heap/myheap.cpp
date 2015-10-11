#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Heap {
public:
    Heap(int capacity){
        this->size = 0;
        this->data = new int[capacity];
    }
    
    ~Heap(){
        delete data;
    }
    
    void push(int v){
        int parent; 
        int currentnode = ++size;
        while((parent = data[currentnode / 2]) < v && currentnode != 1){
            data[currentnode] = parent;
            currentnode /= 2;
        }
        data[currentnode] = v;
    }
    
    void pop(){
        if(size == 0) return;
        int root = data[1];
        int last = data[size--];
        
        int currentnode = 1;
        int child = 2;
        
        while(child <= size){
            if(child < size && data[child] < data[child + 1])
                child++;
            if(last >= data[child])
                break;
            data[currentnode] = data[child];
            currentnode = child;
            child *= 2;
        }
        data[currentnode] = last;
    }
    
    int top(){
        return data[1];
    }
    
    bool empty(){
        return (size == 0);
    }
    
private:
    int size;
    int *data;
};

int main(){
    int t[] = {2, 1, 5, 4, 6};
    Heap h(10);
    for(int i = 0; i < 5; i++)
        h.push(t[i]);
    while(!h.empty()){
        cout << h.top() << endl;
        h.pop();
    }
    
    return 0;
}