#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//template <typename T> class Linkedlist;
class Linkedlist;

//template <typename T>
class Node{
friend class Linkedlist;
public:
    Node(string& data, Node *next, Node *last){
        this->data = data;
        this->next = next;
        this->last = last;
    }

    string data;
    Node *next, *last;
};

//template <typename T>
class Linkedlist{
public:
    class Iterator{
        public:
            Iterator(Node *front){
                currentnode = startnode = front;
            }
            
            Iterator& operator ++(){
                currentnode = currentnode->next;
            }
            
            string& operator *() const {
                return currentnode->data;
            }
            
            string* operator ->() const{
                return &currentnode->data;
            }
            
            bool operator !=(const Iterator it) const{
                return currentnode != it.currentnode;
            }
            
            bool operator ==(const Iterator it) const{
                return currentnode == it.currentnode;
            }
        private:
            Node *startnode, *currentnode;
    };
    
    Linkedlist(){
        front = rear = NULL;
    }
    
    ~Linkedlist(){
        
    }
    
    void insert_back(string& pivot, string& t){
        Node *nptr = find_node(pivot);
        if(nptr != NULL){
            Node *nptr_ori_next = nptr->next;
            nptr->next = new Node(t, nptr->next, nptr);
            if(nptr == rear)
                rear = nptr->next;
            else
                nptr_ori_next->last = nptr->next;
        }
    }
    
    void insert_front(string& pivot, string& t){
        Node *nptr = find_node(pivot);
        if(nptr != NULL){
            Node *nptr_ori_last = nptr->last;
            nptr->last = new Node(t, nptr, nptr->last);
            if(nptr == front)
                front = nptr->last;
            else
                nptr_ori_last->next = nptr->last;
        }
    }
    
    void push_back(string& t){
        if(front == NULL)
            rear = front = new Node(t, NULL, NULL);
        else{
            Node *tmp = rear;
            rear = new Node(t, NULL, NULL);
            tmp->next = rear;
            rear->last = tmp;
        }
    }
    
    void push_front(string& t){
        if(front == NULL)
            rear = front = new Node(t, NULL, NULL);
        else{
            Node *tmp = front;
            front = new Node(t, NULL, NULL);
            front->next = tmp;
            tmp->last = front;
        }
    }
    
    void remove_node(string& t){
        if(front->data == t){
            front->next->last = NULL;
            front = front->next;
        } else
            for(Node *nptr = front; nptr != NULL; nptr = nptr->next){
                if(nptr->data == t){
                    nptr->last->next = nptr->next;
                    nptr->next->last = nptr->last;
                    delete nptr;
                }
            }
    }
    
    Node *find_node(string& t){
        for(Node *nptr = front; nptr != NULL; nptr = nptr->next)
            if(nptr->data == t)
                return nptr;
        return NULL;
    }
    
    Iterator begin(){
        return Iterator(front);
    }
    
    Iterator end(){
        return Iterator(rear);
    }
    

private:
    Node *front, *rear;
};

int main(){
    freopen("in.txt", "r", stdin);
    
    Linkedlist li;
    string s;
    while(cin >> s){
        li.push_front(s);
    }
    
    string rs("Golang");
    string tar("Apple");
    string ftar("Fox");
    
    // Remove
    li.remove_node(rs);
    
    // Insertion
    li.insert_front(tar, rs);
    li.insert_front(ftar, rs);
    
    // Find
    Node *node_find = li.find_node(tar);
    cout << "Find " << tar << endl;
    if(node_find != NULL)
        cout << "Result: " <<node_find->data << endl;
    else
        cout << "Result: Not found" << endl;
    cout << endl;
    
    // Front iterate
    cout << "Front:"<< endl;
    // for(Node *it = li.begin(); it != NULL; it = it->next){
    //     cout << it->data << endl;
    // }
    for(Linkedlist::Iterator it = li.begin(); it != li.end(); ++it){
        cout << *it << endl;
    }
    
    // Rear iterate
    // cout << "\nRear:"<< endl;
    // for(Node *it = li.end(); it != NULL; it = it->last){
    //     cout << it->data << endl;
    // }
    
    
    return 0; 
}