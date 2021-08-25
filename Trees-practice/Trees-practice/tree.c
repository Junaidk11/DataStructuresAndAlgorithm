//
//  queue.c
//  Trees-practice
//
//  Created by jjkhan on 8/24/21.
//

#include "tree.h"
#include "stack.h"

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
         NOTE:
        All tree traversals have a time complexity of o(n) and most of the operations performed on a tree is done in o(n) time.
 
    Tree traversal Analysis:
 
         The number of calls made to traverse the tree is 2*n+1, where n is the number of nodes in the tree - you can get this
         formula by tracing out a recursive tracing tree and count the number of calls, or you can look it like this:
             How many nodes in the tree: n
             How many null pointers in the tree, recall its always n+1 in a tree -> n+1
             Therefore, sum these up -> n+n+1 = 2n+1

         The time complexity is a measures how much work is done, we're already printing each node's, so the time complexity
         is o(n) because we print the data of n-nodes of the tree.

         Moreover, the stack size used in the recursive call is dependent on the height of the tree (formally it is h+2, so o(h)). Recall,
         that for a binary tree, the height of the tree can range between logn < height < n, so the stack size is dependent on tree
        height.
        
 
         Note:that a stack activation record is also created for the NULL pointers (i.e. leaf node's children).
 
 */

/*
    
     Process root/parent node, then recursive call on left-child, followed by recursive call on right-child
            think of a line at the left side of each node, then trace from root node going left, print/process the node you come across
            first
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 */
void Recursive_pre_order(tree_node* node){
    if(node!=NULL){
        
        // Process/Print current node
        printf("%d ",node->data);
        
        // Recursive call on left-subtree
        Recursive_pre_order(node->left_child);
        
        // Recursive call on right-subtree
        Recursive_pre_order(node->right_child);
    }
}
/*
     Recursive call on left-child,  Process root/parent node, followed by recursive call on right-child:
            think of a line at the bottom of each node, then trace from root node going left, print/process the node you come across
            first
                                    
 
   
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 
 
 */
void Recursive_in_order(tree_node* node){
    if(node!=NULL){
        
        // Recursive call on left-subtree
        Recursive_in_order(node->left_child);
        
        // Process/Print current node
        printf("%d ",node->data);
        
        // Recursive call on right-subtree
        Recursive_in_order(node->right_child);
    }
}

/*
     Recursive call on left-child, then recursive call on right-child, followed by Processing root/parent node,
            think of a line at the right of each node, then trace from root node going left, print/process the node you come across
            first
                                    
 
    The tree_node pointer is passed by value, so we can use it to traverse the tree as it is not the original tree root pointer
 */
void Recursive_post_order(tree_node* node){
    if(node!=NULL){
        
        // Recursive call on left-subtree
        Recursive_post_order(node->left_child);
        
        // Recursive call on right-subtree
        Recursive_post_order(node->right_child);
        
        // Process/Print current node
        printf("%d ",node->data);
    }
}
/*
    The traversal iteratively is the same as recursive, you just have to create the stack functionality yourself.
 
    So, for pre-order, you print/process current node. Before, going to the left child, you push the address of the parent node into
    the stack, you do this until you reach the null (i.e. the first parent with no left child), then you pop the address of the previous
    parent node and go to its right child, and repeat the process.
        Therefore, each time you want to go to the next level in the tree, you have to push the address of the current level node to the
        stack so that you can come back to it. Once you hit a dead end, i.e. a null pointer, you pop the top of the stack to go back to
        previous level
            This process is repeated until both the stack is empty and the current node is null. Therefore, if the current node is NULL,
            you pop address of previous level from stack. If current node is not null and you've processed its data, then you can push
            this node's address to the stack and go to either left or right child
 
    Pre-order steps:
                    Process current node
                    Pre_order(left child)
                    Pre_order(right_child)
 */
void Iterative_pre_order(tree_node* node){
    
    // Declare a stack
    stack tree_nodes;
    STACK_Init(&tree_nodes);
    
    // The following are repeated steps
    while(node!=NULL || !STACK_isEmpty(tree_nodes)){
        
        if(node!=NULL){
            // Print/Process current node's data
            printf(" %d", node->data);
            
            // Push this node to the stack
            STACK_push(&tree_nodes, node);
            
            // Update node to the left child
            node = node->left_child;
        }else{
           
            // The current node has no left child
            
            // To go to right child, first we need to go to the parent, which was pushed to the stack in the if-block
            node = STACK_pop(&tree_nodes);
            
            // Now go to right child of this parent node
            node = node->right_child;
        }
    }
    
}
/*
        In-order steps:
                 Pre_order(left child)
                 Process current node
                 Pre_order(right_child)
 
        Using a stack here, similar to recursive implementation.
            Since we visit left child first before we process the parent node, the first step should be push the parent(i.e. current node)
            to the stack, and then visiting the left child.
            If a node has no left child (i.e. reached NULL) then we pop the parent node from the stack, print/process its data, then we visit the right child of this parent.
 
        You repeat this until the stack is empty and the current node is also pointing to NULL.
 */
void Iterative_in_order(tree_node* node){
    
    // Declare a stack
    stack tree_nodes;
    STACK_Init(&tree_nodes);
    
    while(node!=NULL || !STACK_isEmpty(tree_nodes)){
        
        if(node!=NULL){
            
            // Push the node to the stack and visit the left child
            STACK_push(&tree_nodes, node);
            
            // Update node to left child
            node = node->left_child;
        }else{
            
            // Current node has no left child
            
            // Pop the parent node of this node
            node = STACK_pop(&tree_nodes);
            
            // Print/process data of the parent node
            printf(" %d", node->data);
            
            // Update node to the right childd
            node = node->right_child;
        }
    }
}

/*
        Post-order steps:
                 Pre_order(left child)
                 Pre_order(right_child)
                 Process current node
 
        Using a stack here, similar to recursive implementation.
            Since we visit left and right child first before we process the parent node, the first step should be push the
            parent(i.e current node) to the stack, and then visiting the left child.
            If a node has no left child (i.e. reached NULL) then we pop the parent node from the stack, next
            we visit the right child of this parent. But first we need to push the parent again to the stack again because
            we're visiting the right side of the parent now. To differentiate between the first and second push of the same parent
            to the stack, we can push the -negative address second time - address can't be negative but we can store the address as
            a long integer when we push it to the stack second time. Using this information we can print the data of the parent node
            when we reach the end of the right tree.
 
        You repeat this until the stack is empty and the current node is also pointing to NULL.
 */
void Iterative_post_order(tree_node* node){
    
    // Declare a stack for the nodes
    stack tree_nodes;
    STACK_Init(&tree_nodes);
    
    long int address_as_integer;
    
    while(node!=NULL || !STACK_isEmpty(tree_nodes)){
        
        if(node!=NULL){
            
            // Push the parent node to the stack - this is first time
            STACK_push(&tree_nodes, node);
            
            // Move to the left child
            node  = node->left_child;
        }else{
            
            // Left child has no children. Pop parent node address
            address_as_integer = (long int)STACK_pop(&tree_nodes);
            
            // Check if the integer is negative or positive
            if(address_as_integer>0){
                // This is the first time popping the parent node
                // Need to visit the right child
                // also push negative of parent address to the stack now - so that next pop we print/process the parent node data
                STACK_push(&tree_nodes, (tree_node*)(-address_as_integer));
                
                // Move to right child
                node = (tree_node *)address_as_integer;
                node = node->right_child;
                
            }else{
                
                // This is second time popping the parent node
                
                // Convert back to positive long integer - i.e. a valid address
                node = (tree_node *)(-address_as_integer);
                
                // Print parent node data now
                printf(" %d",node->data);
                
                // reset the node pointer to NULL so that next iteration we pop another address from the stack
                node = NULL;
            }
        }
        
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
