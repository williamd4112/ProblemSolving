#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

template <typename K, typename V> class Tree;
template <typename K, typename V>
class Node{
friend class Tree<K, V>;
public:
    Node(K& key, V& value, Node<K, V> *parent, Node<K, V> *left, Node<K, V> *right){
        this->data = pair<K, V>(key, value);
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->leftsize = 1;
        this->rightsize = 1;
    }

    ~Node(){

    }

    void ancestorTraverse(){
        ancestorTraverse(parent);
    }

    void ancestorTraverse(Node<K, V> *_parent){
        if(_parent != NULL){
            cout << _parent->data.first;
            ancestorTraverse(_parent->parent);
        }
    }
    
    pair<K, V> data;
    Node<K, V> *parent, *left, *right;
    int leftsize, rightsize;
};

template <typename K, typename V>
class Tree{
public:
    Tree(){
        this->root = NULL;
    }

    ~Tree(){

    }
    
    Node<K, V>* searchByRank(int rank){
        Node<K, V> *currentnode = root;
        while(currentnode != NULL){
            if(rank < currentnode->leftsize)
                currentnode = currentnode->left;
            else if(rank > currentnode->leftsize){
                rank -= currentnode->leftsize;
                currentnode = currentnode->right;
            }
            else
                return currentnode;
        }
        return NULL;
    }
    
    Node<K, V>* search(K& key){
        search(root, key);
    }

    Node<K, V>* search(Node<K, V>* _root, K& key){
        if(_root == NULL) return NULL;
        else if(key < _root->data.first)
            return search(_root->left, key);
        else if(key > _root->data.first)
            return search(_root->right, key);
        else
            return _root;
    }

    void remove_node(K& key){
        Node<K, V> *rm_node = search(key);
        if(rm_node != NULL){
            if(rm_node->left == NULL && rm_node->right == NULL){ // Leaf-node (0 child)
                if(rm_node->parent->left == rm_node) rm_node->parent->left = NULL;
                else rm_node->parent->right = NULL;
                delete rm_node;
            }
            else if(rm_node->right != NULL && rm_node->left != NULL){ // Non-leaf node (2 child
                Node<K, V> *right_smallest_node = findSmallest(rm_node->right);
                rm_node->data = right_smallest_node->data;
                if(right_smallest_node->right != NULL){
                    if(right_smallest_node->parent->left == right_smallest_node) right_smallest_node->parent->left = right_smallest_node->right;
                    else right_smallest_node->parent->right = right_smallest_node->right;
                } else{
                    if(right_smallest_node->parent->left == right_smallest_node) right_smallest_node->parent->left = NULL;
                    else right_smallest_node->parent->right = NULL;
                }
                
                delete right_smallest_node;
            }
            else if(rm_node->left != NULL){ // Non-leaf with left child
                if(rm_node->parent->left == rm_node) rm_node->parent->left = rm_node->left;
                else rm_node->parent->right = rm_node->left;
                delete rm_node;   
            }
            else if(rm_node->right != NULL){ // Non-leaf with right child
                if(rm_node->parent->left == rm_node) rm_node->parent->left = rm_node->right;
                else rm_node->parent->right = rm_node->right;
                delete rm_node;   
            }
        }
    }

    Node<K, V>* findSmallest(Node<K, V> *_root){
        Node<K, V> *_cur = _root;
        while(_cur->left != NULL){
            _cur = _cur->left;
        }
        return _cur;
    }

    void insert(K& key, V& value){
        root = insert(root, key, value);
    }

    Node<K, V>* insert(Node<K, V> *_root, K& key, V& value){
        if(_root == NULL){
            _root = new Node<K, V>(key, value, NULL, NULL, NULL);
        }
        else if(key < _root->data.first){
            _root->left = insert(_root->left, key, value);
            _root->left->parent = _root;
            _root->leftsize++;
        }
        else if(key > _root->data.first){
            _root->right = insert(_root->right, key, value);
            _root->right->parent = _root;
            _root->rightsize++;
        }
        else{
            Node<K, V> *old = _root;
            _root = new Node<K, V>(key, value, _root->parent, NULL, NULL);
            delete old;
        }
        return _root;
    }
    
    void levelorderIterate(){
        queue<Node<K, V>* > q;
        Node<K, V> *currentnode = root;
        while(currentnode != NULL){
            cout << currentnode->data.second;
            cout <<"(" << currentnode->leftsize << ")";
            if(currentnode->left != NULL) q.push(currentnode->left);
            if(currentnode->right != NULL) q.push(currentnode->right);
            
            if(q.empty()) break;
            
            currentnode = q.front();
            q.pop();
        }
    }
    
    void postorderIterate(){
        stack<Node<K, V>* > st;
        Node<K, V> *currentnode = root, *lastnode = NULL;
        
        while(!st.empty() || currentnode != NULL){
            if(currentnode != NULL){
                st.push(currentnode);
                currentnode = currentnode->left;
            }
            else{
                Node<K, V> *topnode = st.top();
                if(topnode->right != NULL && lastnode != topnode->right)
                    currentnode = topnode->right;
                else{
                    cout << topnode->data.second;
                    lastnode = topnode;
                    st.pop();
                }
            }
        }
        
    }
    
    void preorderIterate(){
        stack<Node<K, V>* > st;
        Node<K, V>* currentnode = root;
        
        while(!st.empty() || currentnode != NULL){
            if(currentnode != NULL){
                cout << currentnode->data.second;
                if(currentnode->right != NULL)
                    st.push(currentnode->right);
                currentnode = currentnode->left;
            }
            else{
                currentnode = st.top(); st.pop();
            }
        }
    }
    
    void inorderIterate(){
        stack<Node<K, V>* > st;
        Node<K, V>* currentnode = root;
        
        while(!st.empty() || currentnode != NULL){
            if(currentnode != NULL){
                st.push(currentnode);
                currentnode = currentnode->left;
            }else{
                currentnode = st.top(); st.pop();
                cout << currentnode->data.second;
                currentnode = currentnode->right;
            }
        }
    }
    
    void inorderTraverse(){
        inorderTraverse(root);
    }

    void inorderTraverse(Node<K, V> *_root){
        if(_root != NULL){
            inorderTraverse(_root->left);
            cout << _root->data.second;
            inorderTraverse(_root->right);
        }
    }

    void preorderTraverse(){
        preorderTraverse(root);
    }

    void preorderTraverse(Node<K, V> *_root){
        if(_root != NULL){
            cout << _root->data.second;
            preorderTraverse(_root->left);
            preorderTraverse(_root->right);
        }
    }
    
    void postorderTraverse(){
        postorderTraverse(root);
    }

    void postorderTraverse(Node<K, V> *_root){
        if(_root != NULL){
            postorderTraverse(_root->left);
            postorderTraverse(_root->right);
            cout << _root->data.second;
        }
    }
private:
    Node<K, V>* root;
};

int main(){
    freopen("in2.txt","r",stdin);
    Tree<int, int> tree;
    int str;
    while(cin >> str)
        tree.insert(str, str);

    int key = 1;
    Node<int, int>* node = tree.search(key);

    node->ancestorTraverse();
    cout << endl;
    
    //tree.remove_node(key);
    
    tree.preorderTraverse();
    cout << endl;
    tree.preorderIterate();
    cout << endl;
    
    tree.inorderTraverse();
    cout << endl;
    tree.inorderIterate();
    cout << endl;
    
    tree.postorderTraverse();
    cout << endl;
    tree.postorderIterate();
    cout << endl;
    
    tree.levelorderIterate();
    cout << endl;
    
    int rank = 5;
    cout << "Search By Rank " << rank << endl;
    Node<int, int> *rank_node = tree.searchByRank(rank);
    if(rank_node != NULL)
        cout << rank_node->data.second << endl;
    else
        cout << "No found " << endl;
    
    return 0;
}
