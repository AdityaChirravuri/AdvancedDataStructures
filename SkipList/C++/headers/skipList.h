#ifndef SKIP_LIST_H
#define SKIP_LIST_H

typedef listNode Node;

class skipList{
private:
    float p;
    int MAX_LEVEL;
    int level;
    Node* head;
public:
    skipList(int, float);
    ~skipList();
};

skipList::skipList(int max_level, float p){
    

}

skipList::~skipList() {
    delete head;
}
#endif