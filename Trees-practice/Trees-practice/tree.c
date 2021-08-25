//
//  queue.c
//  Trees-practice
//
//  Created by jjkhan on 8/24/21.
//

#include "tree.h"



// ======= Tree Node Functions ========
tree_node* create_treenode(int data){
    
    // Allocate memory for the new node
    tree_node *newNode = (tree_node *)malloc(sizeof(tree_node));
    
    if(newNode){
        newNode->data=data;
        newNode->left_child = NULL;
        newNode->right_child =NULL;
    }else{
        printf("Heap is full. Cannot allocate memory for new node.\n");
    }
    
    return newNode;
}



// ======= Tree Node Functions ========

// ======= Tree Traversal Functions ========

/*
    
     Process root/parent node, then recursive call on left-child, followed by recursive call on right-child
            think of a line at the left side of each node, then trace from root node going left, print/process the node you come across
            first
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 */
void pre_order(tree_node* node){
    if(node!=NULL){
        
        // Process/Print current node
        printf("%d ",node->data);
        
        // Recursive call on left-subtree
        pre_order(node->left_child);
        
        // Recursive call on right-subtree
        pre_order(node->right_child);
    }
}
/*
     Recursive call on left-child,  Process root/parent node, followed by recursive call on right-child:
            think of a line at the bottom of each node, then trace from root node going left, print/process the node you come across
            first
                                    
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 */
void in_order(tree_node* node){
    if(node!=NULL){
        
        // Recursive call on left-subtree
        in_order(node->left_child);
        
        // Process/Print current node
        printf("%d ",node->data);
        
        // Recursive call on right-subtree
        in_order(node->right_child);
    }
}

/*
     Recursive call on left-child, then recursive call on right-child, followed by Processing root/parent node,
            think of a line at the right of each node, then trace from root node going left, print/process the node you come across
            first
                                    
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 */
void post_order(tree_node* node){
    if(node!=NULL){
        
        // Recursive call on left-subtree
        post_order(node->left_child);
        
        // Recursive call on right-subtree
        post_order(node->right_child);
        
        // Process/Print current node
        printf("%d ",node->data);
    }
}

// ======= Tree Traversal Functions ========

// ======= Queue Node Functions ========
queue_node* QUEUE_createNode(tree_node *address){
    
    // Allocate memory for node in heap
    queue_node *newNode  = (queue_node *)malloc(sizeof(queue_node));
    
    if(newNode){
        newNode->data = address;
        newNode->next = NULL;
    }else{
        printf("Heap is full. Unable to allocate memory for new node to be added to the queue.");
    }
    
    return newNode;
}
// ======= Queue Node Functions ========

// ======= Queue Operations =======

void QUEUE_initialize(queue *q){
    
    // This queue is created in stack memory of the main function.
    // Its pointers will point to the nodes created in heap for the queue
    
    // Initialize the front and rear pointers of the queue to null
    q->front_ptr = q->rear_ptr = NULL;

}

// Return front element of the queue iff queue is not empty.
tree_node* QUEUE_dequeue(queue *q){
    
    if(QUEUE_isEmpty(*q)){
        printf("Queue overflow.");
        return NULL;
    }
    
    // Queue is not empty.
    
    // place holder for the data of the node - which is the address of a tree_node
    tree_node *address = NULL;
    
    // Create a temp pointer to remove the front node of the queue
    queue_node *temp = NULL;
    
    // Check if the queue only has one node
    if(q->front_ptr==q->rear_ptr){
        // only one node in the queue
        
        // Move temp pointer to the front node (same as rear node here)
        temp = q->front_ptr;
        
        // get address of the tree_node
        address = temp->data;
        
        // free front node
        free(temp);
        
        // reset both front and rear pointers of the queue
        q->front_ptr=q->rear_ptr=NULL;
    }else{
        // Not the only node in the queue
        
        // Move temp pointer to the front node
        temp = q->front_ptr;
        
        // get address of the tree_node
        address = temp->data;
        
        // Update the front pointer of the queue
        q->front_ptr = q->front_ptr->next;
        
        // Free the front node
        free(temp);
    }
    
    
    // return data of the front node - which is address of a node
    return address;
    
}

// Given the address of a tree node,  create a queue node and store the given address in it, followed  by adding the node to
// the back of the queue
void QUEUE_enqueue(queue *q, tree_node *address){
    
    // create a queue node
    queue_node *newNode = QUEUE_createNode(address);
    
    
    // Check if this is the first node
    if(QUEUE_isEmpty(*q)){
        
        // Check if node memory allocated
        if(newNode){
            // Point both rear and front to the first node
            q->front_ptr = q->rear_ptr= newNode;
        }else{
            printf("Queue overflow. \n");
        }
        return;
    }

    // Not the first node, add the new node to the rear of the queue
    
    // Check if node created before you add it to the queue using the rear pointer
    if(newNode){
        
        // Add new node to the end of the queue using rear pointer
        q->rear_ptr->next = newNode;
        
        // Move rear_pointer of the queue to the newly added node
        q->rear_ptr = q->rear_ptr->next;
    }else{
        printf("Queue overflow. \n");
    }

}

int QUEUE_isFull(queue q){
    
    // If you can't allocate memory for a new queue node, then heap is full, consequently the queue is full
    
    // pointer for new queue node
    queue_node *newNode = (queue_node*)malloc(sizeof(queue_node));
    
    // Check if new node has memory allocated
    if(newNode){
        // Memory allocated
        
        // return it to heap
        free(newNode);
        
        return 1;
    }
    
    // Memory not allocated
    return 0;
}

// Queue is empty if the front and rear pointers of the queue are pointing NULL
int QUEUE_isEmpty(queue q){
    
    if(q.front_ptr==NULL && q.rear_ptr==NULL){
        return 1;
    }
    return 0;
}

// ======= Queue Operations =======


// ===================== Additional Functions ========================
/*
    To create a tree, we're going to use a Queue which will stored the address of the nodes in level order traversal.

    
    The idea is:
        Initially, the queue only has the address of the root node. Then the user types in data in the terminal for the left
        and right children respectively. If the data is -1, this node doesn't have that respective child. For every left child
        created, it is passed into the queue, same for the right child.
            This process is repeated until the queue becomes empty, which means the entiire tree has been created in the heap memory.
 */
void create_tree(queue* nodes){
    
    
    // Temp will store the address of the tree_node dequeued  from the queue
    tree_node *temp = NULL;
    
    // data of the node
    int data;
    
    // The following steps are repeated until queue is empty
    while(!QUEUE_isEmpty(*nodes)){
        
        // Get the node address at the front of the queue
        temp = QUEUE_dequeue(nodes);

        printf("Enter %d's left child data. \n", temp->data);
        // Read data from the terminal: -1 means, no left child
        scanf("%d",&data);
        
        // === Adding left child of current node, if requested ====
        if(data!=-1){
           
            // Create left child node
            temp->left_child = create_treenode(data);
            
            // Move this left child into the queue
            QUEUE_enqueue(nodes, temp->left_child);
        }else{
            temp->left_child =  NULL;
        }
        
        
        // === Adding Right child of current node, if requested ====
        
        printf("Enter %d's right child data. \n", temp->data);
        
        // Read data from the terminal: -1 means, no right child
        scanf("%d",&data);
        
        if(data!=-1){
           
            // Create right child node
            temp->right_child = create_treenode(data);
            
            // Move this right child into the queue
            QUEUE_enqueue(nodes, temp->right_child);
        }else{
            temp->right_child =  NULL;
        }
        
    }// End of queue, the entire tree should be created in the heap
    printf("Tree Created.\n");
    
}
// ===================== Additional Functions ========================
