//
//  main.c
//  linkedlists
//
//  Created by jjkhan on 7/13/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For MAX and MIN integer values

// Define Node structure
struct Node{
    int data;
    struct Node* next;
};

// Operations
struct Node* createNode(int data);
void create_list(struct Node** headptr);
void display_list_iterative(struct Node* headptr);
void display_list_recursive(struct Node* headptr);
int list_size(struct Node* headptr);
int sum(struct Node* headptr);
int max(struct Node* headptr);
struct Node* searchList(struct Node* headptr, int key);
struct Node* improved_SearchList(struct Node** headptr, int key);
void insert_node(struct Node** headptr, int position, int data);

// Test Programs
int user_input(void);
void create_and_display_linkedlist(void);
void insert_new_node(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    insert_new_node();
    
    return 0;
}

int user_input(void){
    int data;
    // Need a new line to take user input!
    printf("Enter node data:\n");
    scanf("%d", &data);
    return data;
}


void insert_new_node(void){
    
    // Create a list head pointer
    struct Node* headptr = NULL;
    
    // Create a list
    create_list(&headptr);
    
    // Print the new list
    display_list_iterative(headptr);
    
    // Add new Node to the list
    int index, data;
    printf("\n\nWhere to add new node? Note: Position 0 indicates before first node.\n First input should be index, second input should be data. \n");
    scanf("%d", &index);
    scanf("%d", &data);
    insert_node(&headptr, index, data);
    
    // Print updated list
    display_list_iterative(headptr);
}
// Test passed.
void create_and_display_linkedlist(void){

    // Create head of the linkedlist
    struct Node* head = NULL;
    create_list(&head);
    display_list_iterative(head);
    printf("Reverse list print: ");
    display_list_recursive(head);
    printf("\n");
    printf("List size is: %d\n",list_size(head));
    printf("Sum of all nodes: %d\n", sum(head));
    printf("Max element in the list is: %d\n", max(head));
    printf("Address of Node with \'%d\': %p \n", 4, searchList(head, 4));
    display_list_iterative(head); // before improved search
    printf("Address of Node with \'%d\': %p \n", 4, improved_SearchList(&head, 4));
    display_list_iterative(head); // after improved search
    printf("Address of Node with \'%d\': %p \n", 3, improved_SearchList(&head, 3));
    display_list_iterative(head); // after improved search
    printf("\n");
    
}

/*
    Given the head pointer of a linked list. Take user input, create node, link all nodes,
    to create a list.
    Number of nodes to create is given by size.
 
    The double pointer is needed because in C everything is passed by value.
        The double pointer stores the address of a pointer.
            Visually: headptr_address -> headptr -> firstNode
                        If you dereference once, you get the address stored in headptr, i.e. (*headptr_address)
                        If you dereference twice, you get the data stored in firstNode, i.e. *(*headptr_address)
            
    Note:
        The 'headptr' pointer from the called function has a different location than the
        'headptr' created in this function (i.e. only contents of headptr from calling function is
        passed into this function, not the place holder of the 'headptr'. Therefore,
        you pass the exact address of the 'headptr' to store the nodes created in this function.
     
 */
void create_list(struct Node** headptr_address){
    
    // Headptr should be pointing to nothing to create a list of given 'size'
    // single dereferencing, you're accessing the address stored in the pointer pointed to by
    // headptr
    // double dereferencing is used to access the value in the address pointed to by the pointer
    // pointed by headptr.
    if((*headptr_address)!=NULL){
        printf("List population failed.\n");
        return;
    }else{
        
        // Get list size
        printf("Enter list length: \n");
        int size;
        // Don't add \n in scanf
        scanf("%d",&size);
        // Create first node of the list
        int input = user_input();
        (*headptr_address) = createNode(input);
        size--;
        
        // Create a pointer to traverse the linkedlist
        // iterator pointing to first node right now
        struct Node* iterator = (*headptr_address);
        
        // Create the remaining nodes
        while(size!=0){
            // Get user input for data of the node
            input = user_input();
            // Create a node and initialize it with user data
            // and linked current node to the new node created
            iterator->next = createNode(input);
            // Move iterator forward to the new node
            iterator = iterator->next;
            size--;
        }
    }
}

/*
    Allocate Memory for a node in heap, initialize it with given data
    and return its memory.
 */
struct Node* createNode(int data){
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
    Traverse a linkedlist given the headpointer and print the data of each node.
 
    The headptr in this function argument is not the same address of the headptr
    in the main function -> i.e. the pointer to the function is passed by value.
    
    So, you can use the given headptr to traverse the list without having to create
    an iterator pointer to traverse the list, i.e. you won't lose the head of the list because
    the actual headptr address is different from the headptr used in this function, although both
    point to the same list.
    
 */
void display_list_iterative(struct Node* headptr){
    
    printf("Linkedlist contents are: ");
    
#if 1
    // Using while loop
    while(headptr!=NULL){
        // Print data of current node and move to next node
        printf("%d ", headptr->data);
        headptr = headptr->next;
    }
#elif 0
    // Using for-lopp
    for(;headptr!=NULL;headptr=headptr->next){
        // Print data of current node and move to next node
        printf("%d ", headptr->data);
    }
#endif
    printf("\n");
}

/*
    In this function, the linkedlist is traversed recursively.
    The work done here is simply printing, and we're visiting each node once, therefore, the time
    taken is O(n).
    The number of recursive calls for the linkedlist of n nodes is always n+1, because the
    recursion stops at NULL. Therefore, the space complexity is O(n) but n+1 activation records
    are created in stack.
 
    The time taken to traverse the list recursively and iteratively is the same -> O(n).
    However, recursive traversal takes more space in stack than an iterative traversal.
 
    Moreover, with recursion you can print the linkedlist in reverse by first going to the next node
    and printing/processing the current node when you return from the next node.
    
 */
void display_list_recursive(struct Node* headptr){
    
    // Recursion base case
    if(headptr!=NULL){
#if 1
        // For printing/process the nodes in reverse
        // i.e. last node processed first, first node
        // processed last
        
        // Process next node first
        display_list_recursive(headptr->next);
        // process the current node on return
        printf("%d ",headptr->data);
#elif 0
        // For printing/processing the current node first
        
        // process the current node first
        printf("%d ", headptr->data);
        // Process next node
        display_list_recursive(headptr->next);
        
#endif
    }
}

/*
    In this function, you count the number of nodes in the list and return the count,
    which is the size of the list.
    
    Just like display, this function can be written recursively and iteratively. The time
    complexity of both is O(n) because each node is visited once. The space complexity
    however is constant for an iterative implementation and is O(n) for recursive implementation
    because n+1 activation records will be created to traverse the entire list from first node to
    NULL.

 */
int list_size(struct Node* headptr){
    
#if 0
    // Iterative implementation: Time - o(n) and Space - o(1)
    int length = 0;
    // head points to the first node
    while(headptr!=NULL){
        // Pointing to a node
        // Increment count
        length++;
        
        // Move ahead
        headptr = headptr->next;
    }
    // return length of the list
    return length;
#elif 1
    
    // Recursive Implementation: Time - o(n) , Space -> o(n+1) = o(n)
    if(headptr==NULL){
        // Base case
        // Reach end of list
        return 0;
    }else{
        // Move to the next node and add 1 on return
        // So, if you draw the recursion spannning tree
        // the count starts at the base case (i.e. NULL, the node after last node)
        // and makes it way back to first call with increments by 1
        
        // final size.
        return (list_size(headptr->next) + 1);
    }
#endif
}

/*
    In this function you want to return the sum of all the nodes in the list.
    This can be achieved iteratively and recursively. The time complexity of both will be linear
    because you visit each node only once. The same complexity of the iterative implementaton would
    be constant and the recursive implmentation will be linear because n+1 activation records are
    created to get the sum.
    
    In recursive method, you process the next node first before the current, making your way
    to NULL, which is your base case. Then on your way back to the first call, you add the add of
    last node to the base case, return to second last node and add its data to the sum of last node,
    repeating this procedure, you make your way to the first node.
 
    Note:
        headptr can be used to traverse the list because
        it holds the address of the first node, its not the same pointer that
        as the headptr in caller function because in C all variables are passed by value,
        i.e. only the variable's value is passed to the function, not the Physical variable itself.
 */
int sum(struct Node* headptr){
    
#if 0
    // Iterative implementation
    int sum =0;
    while(headptr!=NULL){
        // Add data of current node to the sum
        sum+= headptr->data;
        
        // Move to the next node
        headptr = headptr->next;
    }
    return sum;
#elif 1

    // Recursive Implementation
    if(headptr==NULL){
        // Reached base case,
        // the pointer points to NULL, which is where the last node was pointing
        return 0;
    }else{
        
        // Move to the next node, and add the current node's data when you
        // return from it
        return (sum(headptr->next) + headptr->data);
    }
#endif

}

/*
    This function returns the maximum element in the linkedlist.
    Returning the value, but we can easily return address of the node that contains the
    max element
 */
int max(struct Node* headptr){
    
#if 0
    // Iterative Implementation
    
    // Place holder maximum int in the given linked list
    // give the current max the minimum possible integer of your system
    // In C, need to include limits.h header file
    int current_max = INT_MIN;
    
    // Use the headptr to traverse the list
    while(headptr!=NULL){
        if(headptr->data>current_max){
            // current node's value is greater than previously
            // found max
            current_max = headptr->data;
        }
        // Move to the next node
        headptr = headptr->next;
    }
    return current_max;

#elif 1
    // Recursive implementation
    // Basically, you traverse to the end of the list
    // in the base case you return the minimum possible value of int
    // then you check that with the last node's data, and return the largest among them
    // to the second last node, repeating this as you make your way to the first node.
    int data;
    if(headptr==NULL){
        // Reached base case
        return INT_MIN;
    }else{
        // Get next node's data
        data = max(headptr->next);
        
        // check if next node's value is greater than current nodes
        // Using ternary operator
        return (data>headptr->data? data:headptr->data);
    }
#endif
    
}

/*
    In a linkedlist, you have to use linear search, where you visit each node
    and check if its data matches your key. You can't use binary search in a linkedlist because
    there is no midpoint in the linked list, because data is not stored contiguously in memory.
 
 */
struct Node* searchList(struct Node* headptr, int key){
   
#if 0
    // Iterative Implementation
    while(headptr!=NULL){
        
        // Check if current node's data matches your key
        if(headptr->data == key){
            // Found the key, return address of current node
            return headptr;
        }
        
        // Move to the next node, key not found in the current node
        headptr = headptr->next;
    }
    
    // Key not found in the list
    return NULL;
#elif 1
    // Recursive implementation
    // You check if the current node's data matches the key
    // if it doesn't, then you call search on next node as headptr
    // this way you recursively traverse to the end of the list,
    // which is your base case, if you reached base case then
    // you haven't found the key in the list
    
    if(headptr==NULL){
        // Base case, you've reached the end of the list
        // key not found in the list
        return NULL;
    }
    
    // Not the end of the list, check the give node's data
    if(headptr->data == key){
        // key found in the current node
        // don't need to search the rest of the list
        // return the node address
        return headptr;
    }
    
    // Key not matching the current node's data, check next node
    return searchList(headptr->next, key);

#endif
}


/*
    This is essentially the same as a Linear search. A linear search can be improved
    by moving the key that is found in the list to the front of the list so that if you look for the
    same key again, it will be found in less number of comparison relative to previous search of the same key.
    
    Since variables in C are passed by value, the head pointer of the list should be passed by reference
    so that you can move the node with the key to the front of the list.
 */
struct Node* improved_SearchList(struct Node** headptr, int key){
    
    // Two pointers to traverse the list as you look for the key in the list.
    // The two pointers will be used to move the node with the key to the front of the list
    // Forward pointer moves ahead as it looks for the node and backward pointer follows
    struct Node *forward = (*headptr), *follower = NULL;
    
    while(forward!=NULL){
        
        if(forward->data==key){
            // key found in the list
            // the previous node is updated to point to the current node's next
            follower->next = forward->next;
            
            // the current node should now point to the existing first node
            forward->next = (*headptr);
            
            // Update head pointer of the list to the new first now, which
            // is the node with the key value
            (*headptr) = forward;
            
            // return the address of the node, which is your first node,
            // could return (*headptr) or return forward, both pointing to the same first node
            return (*headptr);
        }
        // Key not found, move the follower to where forward is first,
        // then move forward to the next node
        follower = forward;
        forward = forward->next;
    }
    
    return NULL;
}


/*
    In this function, you're adding a new node to the linkedlist at any given position.
 
    The position is indices to indicate where to insert the new node.
    All nodes in the given linkedlist start from 1 to the last node. Therefore, a position = 0, means insert new node at the front,
    a position =1 mean insert new node after first node etc.
    
    The minimum time to insert a node in the given linkedlist is taken when you're inserting the node before or after the
    node, i.e. O(1). This is because you don't have to traverse the list to find the position, simply updating links between the
    new node and the node at the first position in the list.
 
    The maximum time to insert is if you insert a new node after the last node in the linked list. In this case, you need to
    traverse the list by moving a pointer n times to get to the end of the list and then updating the links between the new node and
    the last node.  Therefore, time taken is o(n).
 
    Note, if the given position of insertion is 'k', then the traversing pointer (aka iterator) will shift k-1 times to come to the node
    after which you want to insert the new node.
 
    Therefore, insertion anywhere in the middle of the list takes O(k-1) time, which is simply o(k), i.e. linear time.

    Note: The double pointer needed to store the head pointer address of the list as we're going to update the list
    
 */
void insert_node(struct Node** headptr, int position, int data){
    
    // Create two pointers, one for traversing the list and the other to hold address of new node
    struct Node *forward = (*headptr), *newNode;
    
    if(position == 0){
        // Inserting the new node at the front, i.e before the first node
        
        // Create new node
        newNode = createNode(data);
        
        // Update links between newNode and existing first node
        
        // New node is linked to the existing first node
        newNode->next = forward;
        
        // headpointer of the list is now pointing to the new first node
        (*headptr) = newNode;
    }else if(position>0){
        
        // Inserting the new node anywhere other than before first node
        
        // Jump to the node in the list, after this node we add the new node
        int i;
        
        // Two loop termination conditions, the second one is added to tackle
        // the scenario where the given list has 5 nodes and the position given is 10 -> which is non-existing
        for(i=0; i<position-1 && forward!=NULL; i++){
            
            // Mover forward in the list to the correct node
            forward = forward->next;
        }
        
        // Before you create the new node and update the links, check if list traverser is pointing
        // to a valid node in the list, could check with if(forward) or if(forward!=NULL) b/c NULL=0=false
        if(forward!=NULL){
            
            // Create new node
            newNode = createNode(data);
            
            // update the link between new node and the existing node at "position"
            
            // New node linked to the next node in the list, i.e. node at "position+1"
            newNode->next = forward->next;
            
            // new node is now at "position"
            forward->next = newNode;
        }
    }
}
