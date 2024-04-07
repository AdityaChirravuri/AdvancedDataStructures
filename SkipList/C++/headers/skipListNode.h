#ifndef SKIP_LIST_NODE_H
#define SKIP_LIST_NODE_H

class listNode{
private:
    int key;
    int *value;
    listNode** next;
    int GetKey() const{}
    void SetKey(int key) {}
    int *GetValue() const {}
    void SetValue(int *value){}
    listNode** GetNext() const {}
    void SetNext(listNode** next){}

public:
    listNode(int, int );
    ~listNode();   
};

listNode::listNode(int key, int level) {
        this->key = key;
        value = nullptr;
        next = new listNode*[level+1];
        memset(next, 0, sizeof(listNode)*(level+1));
}

listNode::~listNode() {
        delete[] next;
        delete value;
}

int listNode::GetKey() const {
    return key;
}

void listNode::SetKey(int key) {
    key = key;
}

int* listNode::GetValue() const{
    return value;
}

void listNode::SetValue(int *value) {
    value = value;
}

listNode** listNode:: GetNext() const {
    return next;
}

void listNode::SetNext(listNode** next) {
    next = next;
}


#endif