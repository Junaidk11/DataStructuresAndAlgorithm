#include "Node.h"

Node::Node(){
    this->nextNode= NULL;
}
Node::Node(int x){
    this->data = x; 
    this->nextNode = NULL;
}

Node::~Node(){
    delete this; // Delete the calling object
}

int Node::getData(){
    return this->data;
}

Node* Node::getNextNode(){
    return this->nextNode;
}

void Node::setData(int x){
    this->data =x;
}

void Node::setNextNode(Node* nextNodePtr){
    this->nextNode = nextNodePtr;
}