#ifndef SKIP_LIST_H
#define SKIP_LIST_H

typedef listNode Node;

class skipList{
    float p;
    int MAX_LEVEL;
    int level;
    Node* head;
public:
    skipList(int, float);
    ~skipList();
    //@@ getters and Setters
    float skipList::GetP() const {}
    void skipList::SetP(float p) {}
    int skipList::GetMAX_LEVEL() const {}
    void skipList::SetMAX_LEVEL(int MAX_LEVEL) {}
    int skipList::GetLevel() const {}
    void skipList::SetLevel(int level){}
    Node* skipList::GetHead() const {}
    void skipList::SetHead(Node* head) {}

    Node* createNode(int, int);
    void insertNode(int, int*);
};

skipList::skipList(int max_level, float p){
    this->MAX_LEVEL = max_level;
    this->p = p;
    level = 0;
    head = new Node(INT_MIN, max_level);
}

skipList::~skipList() {
    delete head;
}

float skipList::GetP() const {
    return p;
}

void skipList::SetP(float p) {
    p = p;
}

int skipList::GetMAX_LEVEL() const {
    return MAX_LEVEL;
}

void skipList::SetMAX_LEVEL(int MAX_LEVEL) {
    MAX_LEVEL = MAX_LEVEL;
}

int skipList::GetLevel() const {
    return level;
}

void skipList::SetLevel(int level) {
    level = level;
}

Node* skipList::GetHead() const {
    return head;
}

void skipList::SetHead(Node* head) {
    head = head;
}

Node* skipList::createNode(int key, int level){
    Node* newNode = new Node(key, level);
    return newNode;
}

void skipList::insertNode(int key, int* value){
    Node* cur = head;
    Node* update[MAX_LEVEL+1];
    memset(update, 0, sizeof(Node*)*(MAX_LEVEL+1));

    for(int pos=level; pos>=0; pos--){

    }
}
#endif