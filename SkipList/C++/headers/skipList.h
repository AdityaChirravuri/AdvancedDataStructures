#ifndef SKIPLIST_H
#define SKIPLIST_H

class SkipListNode {
public:
    int key;
    int value;
    SkipListNode** forward;
    SkipListNode(int k, int v, int level);
    ~SkipListNode();
};

class SkipList {
    int maxLevel;
    int level;
    float p;
    SkipListNode* header;

public:
    SkipList(int maxL, float prob);
    ~SkipList();
    int randomLevel();
    void insertNode(int key, int value);
    void deleteNode(int key);
    SkipListNode* search(int key);
    void displayList();
};

#endif