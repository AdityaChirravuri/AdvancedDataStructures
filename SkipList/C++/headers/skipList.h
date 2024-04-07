#include "iostream"
#include "skipListNode.h"

typedef skipListNode Node;

class skipList{
public:
    skipList* next;
    Node* data;

    skipList();
    // skipList(int, int);
    ~skipList();
};

skipList::skipList(){
    this->next = NULL;
    this->data = new Node();

}

skipList::~skipList() {}