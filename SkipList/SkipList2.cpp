#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Node{
private:
    int key;

public:
    void setKey(int);
    int getKey();
    std::vector<Node* >arr;
    Node(int, int);
    ~Node();
};

class skipList{
public:
    skipList* next;
    Node* data;
};

int main(){

    return 0;
}

//this is for each Node
Node::Node(int key, int level){
    this->setKey(key);
    arr.resize(level+1, nullptr);
}

int Node::getKey(){
    return this->key;
}

void Node::setKey(int key){
    this->key = key;
}