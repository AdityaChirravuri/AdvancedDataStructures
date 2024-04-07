#include <iostream>
#include <cstdlib>
#include <limits.h>

#include "headers/SkipList.h"

SkipListNode::SkipListNode(int k, int v, int level) {
    key = k;
    value = v;
    forward = new SkipListNode*[level + 1];
    std::fill_n(forward, level + 1, nullptr);
}

SkipListNode::~SkipListNode() {
    delete[] forward;
}

SkipList::SkipList(int maxL, float prob) {
    maxLevel = maxL;
    p = prob;
    level = 0;
    header = new SkipListNode(INT_MIN, INT_MIN, maxLevel);
}

SkipList::~SkipList() {
    delete header;
}

int SkipList::randomLevel() {
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < p && lvl < maxLevel) {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
}

void SkipList::insertNode(int key, int value) {
    SkipListNode* current = header;
    SkipListNode* update[maxLevel + 1];
    std::fill_n(update, maxLevel + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->key != key) {
        int rlevel = randomLevel();

        if (rlevel > level) {
            for (int i = level + 1; i < rlevel + 1; i++)
                update[i] = header;
            level = rlevel;
        }

        SkipListNode* newNode = new SkipListNode(key, value, rlevel);

        for (int i = 0; i <= rlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void SkipList::deleteNode(int key) {
    SkipListNode* current = header;

    SkipListNode* update[maxLevel + 1];
    std::fill_n(update, maxLevel + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        delete current;

        while (level > 0 && header->forward[level] == nullptr)
            level--;
    }
}

SkipListNode* SkipList::search(int key) {
    SkipListNode* current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
    }
    current = current->forward[0];

    if (current != nullptr && current->key == key)
        return current;
    else
        return nullptr;
}

void SkipList::displayList() {
    std::cout << "Skip List:" << std::endl;
    for (int i = 0; i <= level; i++) {
        SkipListNode* node = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << "(" << node->key << "," << node->value << ") ";
            node = node->forward[i];
        }
        std::cout << std::endl;
    }
}

int main() {
    SkipList list(10, 0.5);

    for(int i=0; i<100; i++){
        int key = rand()%100000;
        int value = rand()%100000;
        list.insertNode(key, value);
    }

    list.displayList();
    return 0;
}

/*
// Search for a node
    SkipListNode* node = list.search(19);
    if (node != nullptr)
        std::cout << "Node with key 19 found, value: " << node->value << std::endl;
    else
        std::cout << "Node with key 19 not found" << std::endl;

    // Delete a node
    list.deleteNode(19);

    // Display the updated skip list
    list.displayList();

*/