#include "Node.h"

Node::Node(){
    this->next=NULL;
}

Node::Node(int x){
    this->data=x;
    this->next=NULL;
}

Node::~Node(){
    delete this;
}

int Node::getData(){
    return data;
}
Node* Node::getNextNode(){
    return next;
}

void Node::setData(int x){ 
    this->data = x;
}

void Node::setNextNode(Node* node_ptr){
    this->next=node_ptr;
}