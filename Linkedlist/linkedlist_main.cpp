#include "Node.cpp"
#include "linkedlist.cpp"

int main(){

    int x;
    // Add First node to the list
    cout << "Enter an integer:" << endl; 
    scanf("%d",&x);
    Node* item = new Node(x);
    linkedlist* l = new linkedlist; 
    l->addNodeToFront(item);
    l->printList();
    

    // Add a new node to the front of the list
    cout << "Enter an integer to add to the front of the list:" << endl; 
    scanf("%d",&x);
    Node* item2 = new Node(x);
    l->addNodeToFront(item2);
    l->printList();
    

    // Add a new node to the end of the list
    cout << "Enter an integer to the end of the list:" << endl; 
    scanf("%d",&x);
    Node* item3 = new Node(x);
    l->addNodeToEnd(item3);
    l->printList();
   

    // Add a new node to the end of the list
    cout << "Enter an integer to the end of the list:"  << endl; 
    scanf("%d",&x);
    Node* item4 = new Node(x);
    l->addNodeToEnd(item4);
    l->printList();
    
    
    // Add a new node to the Front of the list
    cout << "Enter an integer to the front of the list:"  << endl; 
    scanf("%d",&x);
    Node* item5 = new Node(x);
    l->addNodeToFront(item5);
    l->printList();
    

    // Add a new node to the Front of the list
    cout << "Enter an integer to the front of the list:" << endl; 
    scanf("%d",&x);
    Node* item6 = new Node(x);
    l->addNodeToFront(item6);
    l->printList();
    
   

    // Search for a node in the list with data == x
    cout << "Enter an integer to look for in your linkedlist:" << endl; 
    scanf("%d",&x);
    if(l->searchList(x)==NULL){
        printf("Integer not found in the list. \n");
    }else{
        printf("The address of the first node that contains your requested integer: %p.\n", l->searchList(x));
    }

    // Delete a node from the  list
    cout << "Enter an integer to delete from your linkedlist:" << endl; 
    scanf("%d",&x);
    if(l->deleteNode(x)){
        printf("Delete successful.\n");
    }else{
        printf("Delete failed - Integer not found or delete operation failed. \n");
    }
    l->printList();

    // Release memory allocated in the heap
    free((void*)item);
    free((void*)item2);
    free((void*)item3);
    free((void*)item4);
    free((void*)item5);
    free((void*)item6);
    free((void*)l); 
    return 0;
}