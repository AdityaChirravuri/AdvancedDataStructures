#ifndef SKIP_LIST_NODE_H
#define SKIP_LIST_NODE_H

class listNode{
    int key;
    int *value;
    listNode** next;
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
#endif