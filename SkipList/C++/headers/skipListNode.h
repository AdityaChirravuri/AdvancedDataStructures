class skipListNode{
public:
    int getKey() const;
    void setKey(int);

    int getLevel() const;
    void setLevel(int);

    skipListNode(int, int);
    skipListNode();
    ~skipListNode();
private:
    int key;
    int level;
};

//Methods
int skipListNode::getKey() const{
    return this->key;
}

void skipListNode::setKey(int key){
    this->key = key;
}

int skipListNode::getLevel() const{
    return this->level;
}

void skipListNode::setLevel(int level){
    this->level = level;
}

skipListNode::skipListNode() {}
skipListNode::skipListNode(int key, int level) {
    this->level = level;
    this->key = key;
}

skipListNode::~skipListNode() {}