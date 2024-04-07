//debug the code
#include <iostream>
#include <vector>
#include <limits.h>

#include "headers/skipListNode.h"
#include "headers/skipList.h"

typedef skipListNode Node;

using namespace std;

void printSkipList(skipList* head);

int main(){
    skipList* head = new skipList();
    skipList* tail = head;
    for(int i=0; i<25; i++){
        Node* temp = new Node(i, 0);
        skipList* cur = new skipList();
        cur->data = temp;
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }

    printSkipList(head);

    return 0;
}

void printSkipList(skipList* head){
    while(head){
        std::cout << head->data->getKey() << " " << head->data->getLevel() << "\n";
        
        head = head->next;
    }
}