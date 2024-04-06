//debug the code
#include <iostream>
#include <vector>
#include <time.h>
#include <limits.h>

using namespace std;

class Node{
private:
    int key;
    int level;
public:
    void setKey(int);
    int getKey();
    void setLevel(int);
    int getLevel();
    std::vector<Node* >arr;
    Node(int, int);
    Node(int);
    ~Node();
};

class skipList{
public:
    skipList* next;
    Node* data;

    skipList(Node* );
    skipList();
    // skipList(int, int);
    ~skipList();
};

void printSkipList(skipList* head);

int main(){
    skipList* head = new skipList();
    skipList* tail = head;
    for(int i=0; i<25; i++){
        Node* temp = new Node(i, 0);
        skipList* cur = new skipList(temp);
        tail->next = cur;
        tail = cur;
    }

    printSkipList(head);

    return 0;
}

void printSkipList(skipList* head){
    while(head){
        std::cout << head->data->getKey();
        
        head->next;
    }
}


//this is for each Node
Node::Node(int key, int level){
    this->setKey(key);
    this->setLevel(level);
    arr.resize(level+1, nullptr);
}

Node::Node(int level){
    this->setKey(INT_MIN);
    arr.resize(level+1, nullptr);
}

int Node::getKey(){
    return this->key;
}

void Node::setKey(int key){
    this->key = key;
}

void Node::setLevel(int level){
    this->level = level;
}

int Node::getLevel(){
    return this->level;
}

//this is for skip list
skipList::skipList(){
    this->next = NULL;
    this->data = new Node(0);

}

skipList::skipList(Node* head) {

}

skipList::~skipList() {}