#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    vector<Node*> forward;
    Node(int, int);
    ~Node();
};

Node::Node(int key, int level) : key(key), forward(level + 1, nullptr) {}

Node::~Node() {}

class SkipList {
    Node *header;
public:
    SkipList();
    ~SkipList();
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void deleteElement(int);
    void searchElement(int);
    void displayList();
    int getMaxLevel(int);
};

SkipList::SkipList() : header(new Node(INT_MIN, 0)) {}

SkipList::~SkipList() {
    Node *current = header->forward[0];
    while (current != nullptr) {
        Node *next = current->forward[0];
        delete current;
        current = next;
    }
    delete header;
}

int SkipList::randomLevel() {
    int lvl = 0;
    while ((rand() / (float)RAND_MAX) < 0.5) {
        lvl++;
    }
    return lvl;
}

Node* SkipList::createNode(int key, int level) {
    Node *newNode = new Node(key, level);
    return newNode;
}

void SkipList::insertElement(int key) {
    int level = getMaxLevel(randomLevel());
    vector<Node*> update(level + 1, nullptr);
    Node *current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];

    if (current == nullptr || current->key != key) {
        Node *newNode = createNode(key, level);
        for (int i = 0; i <= level; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void SkipList::deleteElement(int key) {
    vector<Node*> update(header->forward.size(), nullptr);
    Node *current = header;

    for (int i = header->forward.size() - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];

    if (current != nullptr && current->key == key) {
        for (int i = 0; i < current->forward.size(); i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        delete current;
    }
}

void SkipList::searchElement(int key) {
    Node *current = header;
    for (int i = header->forward.size() - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
            current = current->forward[i];
    }
    current = current->forward[0];
    if (current != nullptr && current->key == key)
        cout << "Found key: " << key << endl;
    else
        cout << "Not Found key: " << key << endl;
}

void SkipList::displayList() {
    cout << "Skip List:" << endl;
    for (int i = header->forward.size() - 1; i >= 0; i--) {
        Node *node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr) {
            cout << node->key << " ";
            node = node->forward[i];
        }
        cout << endl;
    }
}

int SkipList::getMaxLevel(int rlevel) {
    int level = 0;
    while ((rand() / (float)RAND_MAX) < 0.5 && level < rlevel) {
        level++;
    }
    return level;
}

bool operations(SkipList* skipList){
    int op=-1, key;
    cin >> op;
    switch(op){

        case 1:
            cout << "Enter Key: \n";
            cin >> key;
            skipList->insertElement(key);
        break;

        case 2:
            cout << "Enter Key: \n";
            cin >> key;
            skipList->deleteElement(key);
        break;

        case 3:
            skipList->displayList();
        break;

        case 4:
            cout << "Max Level in the Skip List: " << skipList->getMaxLevel(INT_MIN) << "\n";
        break;

        case 5:
            cout << "Enter Key: \n";
            cin >> key;
            skipList->searchElement(key);
        break;

        case 6:
            return false;
        break;

        
            cout << "Invalid Operations";
        break;
    }

    return true;
}   

int main() {
    SkipList* skipList = new SkipList();
    bool loop = true;
    while(loop){
        cout << "1: Insert Element into Skip List\n";
        cout << "2: Delete Element from Skip List\n";
        cout << "3: Display Skip List\n";
        cout << "4: Get the maximum Height of the List\n";
        cout << "5: Search Element in the Skip List\n";
        cout << "6: Exit\n";

        loop = operations(skipList);
    }

    return 0;
}