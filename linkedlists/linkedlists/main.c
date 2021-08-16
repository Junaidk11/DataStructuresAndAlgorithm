//
//  main.c
//  linkedlists
//
//  Created by jjkhan on 7/13/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For MAX and MIN integer values
#include <stdbool.h> // for bool definition

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
void insert_last(struct Node** headptr, struct Node** lastptr, int data);
void insert_node_sorted_list(struct Node** headptr, int data);
void delete_node(struct Node **headptr, int index);
bool isSorted(struct Node *headptr);
void remove_duplicates(struct Node *headptr);
void reversing_linkedlist_via_elements(struct Node *headptr);
void reversing_linkedlist_via_links(struct Node **headptr);
void reversing_linkedlist_via_links_recursively(struct Node **headptr);

// Test Programs
int user_input(void);
void create_and_display_linkedlist(void);
void insert_new_node(void);
void insert_last_for_creating_a_list(void);
void insert_node_in_a_sorted_list(void);
void delete_node_at_given_index(void);
void check_if_list_sorted(void);
void removeDuplicates(void);
void reverselist(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    reverselist();
    
    return 0;
}

// Reversing list by reversing list node data -> test passed.
// Reversing list by reversing list node links -> test passed.
// Reversing list by reversing list node links using recursion -> test passed.
void reverselist(void){
    
    // ===========================   Reversing list by changing node data ===========================
    // Declare head pointer of the list
    struct Node *headptr = NULL;
    
    // Create a list
    create_list(&headptr);
    
    // Print the list
    display_list_iterative(headptr);
    
    printf("Reversing list by reversing node data.\n");
    
    reversing_linkedlist_via_elements(headptr);
    
    // Print result
    display_list_iterative(headptr);
    
    free(headptr);
    
    // ===========================   Reversing list by changing node links ===========================
    // Declare head pointer of the list
    struct Node *headptr1 = NULL;
    
    // Create a list
    create_list(&headptr1);
    
    // Print the list
    display_list_iterative(headptr1);
    
    printf("Reversing list by reversing node links.\n");
    
    reversing_linkedlist_via_links(&headptr1);
    
    // print result
    
    display_list_iterative(headptr1);
    
    free(headptr1);
    
    // ===========================   Reversing list by changing node links using recursion ===========================
    // Declare head pointer of the list
    struct Node *headptr2 = NULL;
    
    // Create a list
    create_list(&headptr2);
    
    // Print the list
    display_list_iterative(headptr2);
    
    printf("Reversing list by reversing node links.\n");
    
    reversing_linkedlist_via_links_recursively(&headptr2);
    
    // print result
    
    display_list_iterative(headptr2);
    
    free(headptr2);
   
    
}
// Tests passed: Checked with no duplicates, checked with list with all duplicates.
// Note: To remove duplicates, the list has to be sorted first, if not sorted, will miss duplicates: i.e. 8,6,8,4,4 -> will give 8,6,8,4
void removeDuplicates(void){
    // Declare head pointer of the list
    struct Node *headptr = NULL;
    
    // Create a list
    create_list(&headptr);
    
    // Print the list
    display_list_iterative(headptr);
    
    printf("Removing duplicates.\n");
    
    remove_duplicates(headptr);
    
    // print resulting list
    display_list_iterative(headptr);
    
}


int user_input(void){
    int data;
    // Need a new line to take user input!
    printf("Enter node data:\n");
    scanf("%d", &data);
    return data;
}

// Tests passed: Checked with a sorted list and an unsorted list
void check_if_list_sorted(void){
    
    // Two list pointers, one list will be sorted and the other will not be sorted
    struct Node *headptr1 = NULL, *headptr2=NULL;
    
    // Create sorted list
    printf("Create a sorted list - list1\n");
    create_list(&headptr1);
    display_list_iterative(headptr1);
    printf("\n");
    
    // Create an unsorted list
    printf("Create a sorted list - list2 \n");
    create_list(&headptr2);
    display_list_iterative(headptr1);
    printf("\n");
    
    // Check if list sorted
    printf("Is list1 sorted? %d \n",isSorted(headptr1));
    printf("Is list2 sorted? %d \n",isSorted(headptr2));
    
}


// Tests passed: Deleting first node, deleting any node other than first node, not deleting given index is out of bounds of list length.
void delete_node_at_given_index(void){
    
    // Declare head pointer of the list
    struct Node *headptr = NULL;
    
    // Create a list
    create_list(&headptr);
    
    // Print the list
    display_list_iterative(headptr);
    
    printf("Deleting node at index: %d \n", 1);
    // Delete first node
    delete_node(&headptr, 1);
    
    // print updated list
    display_list_iterative(headptr);

    printf("Deleting node at index: %d \n", 3);
    // Delete a node somewhere other than first
    delete_node(&headptr, 3);
    
    // print updated list
    display_list_iterative(headptr);
    
    printf("Deleting node at index: %d \n", 10);
    // Give an index greater than list size
    delete_node(&headptr, 10);
    
    // print updated list
    display_list_iterative(headptr);
}



// Tests Passed:  Adding new node to the front of the list. Adding the new node somewhere b/w first and last node. Adding new node to the end of the list. 
void insert_node_in_a_sorted_list(void){
    
    // Declare list head
    struct Node *headptr = NULL;
    
    // create a list
    create_list(&headptr);
    
    // Print list created
    display_list_iterative(headptr);
    
    // take user input where to add the new node
    int data;
    
    // Going to test three insertion position: 1) Before the first element,2) Inertion somewhere between first and last node, 3) After the last node
    int i;
    for(i=0; i<3; i++){
        
        printf("Enter data to add to the sorted list.\n");
        scanf("%d",&data);
        
        // Add a new node to the list
        insert_node_sorted_list(&headptr, data);
        
        // Print updated list
        display_list_iterative(headptr);
    
    }
    
}

// Tests passed : only adding element to the end of the list.
void insert_last_for_creating_a_list(void){
    
    // Store pointer to the front and end of the list
    struct Node *headptr = NULL, *lastptr = NULL;
    
    int numberOfNodes =0;
    printf("How many nodes do you want to add?\n");
    scanf("%d",&numberOfNodes);
    int i;
    for(i=0;i<numberOfNodes;i++){
        int nodeData =0;
        printf("Enter node data.\n");
        scanf("%d", &nodeData);
        insert_last(&headptr, &lastptr, nodeData);
        display_list_iterative(headptr);
    }
}

// Tests passed: Adding element anywhere in the list, nodes in the list are to from 1 to last node.
//               The spaces between the nodes are referenced as 0-(lastnode-1). Therefore, index = 0 is adding node before first
//               node, i.e. adding to the front of the list.
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

/*
    In this function, we can create an entire linked list by inserting an element only at the end.
    This only works if you only add new nodes ONLY at the end of the existing list.
 
    Without this function, to add a node to the end of the list,
    you would need to traverse the list to the last node and
    then update the links between the new node and the last node, this takes maximum time to insert new node in the lsit -> o(n)
 
    However, if you maintain a pointer to the last node of a list, then you can add a new node to the end of the list in
    constant time -> o(1), the only downfall is extra space used to store pointer to the last node, as always to improve time, you
    have to give up space.
 */
void insert_last(struct Node** headptr, struct Node** lastptr, int data){
    
    
    // Create the new node
    struct Node* newNode = createNode(data);
    
    // Check if current list is empty
    // Both head and last are at the same place
    if((*headptr)==NULL){
        // both head and last node pointer point to the new node
        (*headptr)=(*lastptr)=newNode;
    }else{
        
        // update links between new node and the last node
        // i.e. current last node is now linked to the newNode
        (*lastptr)->next = newNode;
        
        // newNode is the updated last node
        (*lastptr)=newNode;
    }
}

/*
    In this function you add a new node in a sorted list.
    
    The idea: Use two pointers to the list, one is moving forward and the second is following. The forward pointer will find the position to insert.
              The follower will help insert the new node.
    
    The minimum time taken to insert would be o(1) if the node is being inserted after/before the first node.
    The maximum time taken would be o(n) because the two pointers will traverse the list to find the position to insert the new node.
 
    The double pointer is used for scenario where the given data is less than current first node, then you need to add a new node to the front of the list,
    which would require updating the list's head pointer.
    
 */
// Assuming the list is sorted in ascending order
void insert_node_sorted_list(struct Node** headptr, int data){
    
    // check if the given data is less than or equal to the first node
    // if it is, then you add new node to the front of the list.
    if(data <= (*headptr)->data){
        // Add new node to the front of the list
        // headptr pointer stores the actual address of head pointer of the given linkedlist
        insert_node(headptr, 0,  data);
    }else{
        
        // The new node will be somewhere after the first node.
        
        // Declare two pointers to traverse the list.
        struct Node *forward = (*headptr), *follower = NULL;
        
        // Traverse the list and find the position to insert new node
        // Termination is if you reach end of list or you find a node with data greater than given data for new node
        while((forward!=NULL) && (forward->data < data)){
            // Follower will move to where forward is
            follower = forward;
            
            // forward will move to the next node
            forward = forward->next;
        }
        
        // check if your forward is a valid node to insert the new node before
        // We do this check because we're adding new node to the end of the list
        if(forward!=NULL){
            
            // Create the new node
            struct Node *newNode = createNode(data);
            
            // update links between new node and follower
            
            // New node will link to the node with data greater than
            newNode->next = forward;
            
            // follower will link to the new node because its data is less than the new node
            follower->next = newNode;
        }else{
            
            // the new node should be added to the end of the list as its value is greater than the last node in the list
            // the "follower" is at the last node in the list (i.e. pointing to it, because forward is at NULL
            // follower is a pointer to the last node in the list and we already have the head pointer of the list ->  use insert to last function written before
            insert_last(headptr, &follower, data);
        }
        
    }
    
    
}


/*
 
    In this function you delete the node at the given index.
    Note: Nodes are indexed 1 onwards.
    
    Two scenarios of deleting a node:
            1) Delete the first node -> means updating head pointer
            2) Delete anywhere after the first node, doesn't require updating the head pointer
 
    Analysis:
            Deleting the first node is done in constant time. -> o(1)
            Deleting the last node takes the maximum time. -> o(n)
            You need two pointers to delete a node, one to find the node to delete, the other is used to update link of the node before the node you want to delete.
                Therefore, you only update one link in the list to delete a node.
 */
void delete_node(struct Node **headptr, int index){
    
    // Check if the list is empty, if so, can't delete a node
    if(headptr==NULL){
        return;
    }
    
    // Create two pointers, one is moving forward to find the node to delete and the other is following (used for updating link)
    struct Node *forward = (*headptr), *follower = NULL;
    
    // Check if its the first node or some other node in the list.
    if(index==1){
        // Deleting first node
        // Move headptr to the link pointed to by the first node (i.e. where forward is currently pointing to
        (*headptr) = forward->next;
        
        // Deallocate memory appointed to first node
        // Note, you could return the data in this node before deleting it
        free(forward);
        return;
        
    }else{
        
        // Move the 'forward' and 'follower' pointers until 'forward' reaches the 'index' node of the list
        int i;
        for(i=1; i<index && forward!=NULL; i++){
        
            // Move follower to where forward is
            follower = forward;
            // Move forward pointer to the next node
            forward = forward->next;
        }
        
        // Now forward should be pointing to the node that you want to delete and follower should
        // be at node behind it
        if(forward!=NULL){
            
            // Link node at 'index-1' to the node at 'index+1'
            follower->next = forward->next;
            
            // Deallocate memory for the node at 'index'
            free(forward);
            return;
        }
        
    }
    // If you reached here then the 'index' given was larger than the length of the list -> no node deleted
    return;
}

/*
        In this function you're checking of the given linked list is sorted.
 
        The idea is to use a pointer to traverse the list and a variable to store the data of the previous node as you move forward.
            At each node, you check if the current data is less than previous node's data (which is stored in a variable), if true
            you move forward else you return false to indicate list not sorted - assuming the list should be sorted in ascending order.
        
        This checking algorithm has a max time of o(n) if the list is sorted because you traverse full list.
        And minimum time could be the second node itself is not in the correct order so could algorithm executes at constant time.
 
        Overall, you don't need extra pointers because the headptr can be used to traverse the list since its a copy of the original headptr
        therefore you won't lose the head of the list outside of this function call.
*/
bool isSorted(struct Node *headptr){
    
    // Check if list is empty, if it is then return false
    if(headptr==NULL){
        return false;
    }
    
    // Assign lowest value of integer to place holder of node data
    // we're checking if the list sorted in ascending order
    int previousNodeData = INT_MIN;
    
    while(headptr!=NULL){
        
        // Check for false condition to terminate loop - i.e. condition where the list would not sorted in ascending order
        if(headptr->data < previousNodeData){
            // list not sorted in ascending order
            return false;
        }
        
        // store current node's data
        previousNodeData = headptr->data;
        
        // move to next node
        headptr = headptr->next;
    }
    
    // If you reached here the list is sorted in ascending order
    return true;
}


/*
    The list has to be sorted to remove duplicates from it.
    The idea is to use to 2 pointers: the two pointers point to two consecutive nodes, i.e. current node and its nextt
        Check if the current and next node have the same data. If they do, then you remove the second node by making current node point to
        what the next is point to, else you update the two pointers as traversing the list.
    The procedure continues until the second pointer points to null because we're always removing the second node (if current and next have same data)
    
    Time complexity is always O(n) because you will always traverse the entire list. Moreover, you need two additional list pointers.
 */
void remove_duplicates(struct Node *headptr){
    
    // Declare two pointers for two consecutive nodes
    struct Node* currentNode = headptr;
    struct Node* nextNode  = currentNode->next;
    
    
    while(nextNode!=NULL){
        // Check if the two nodes have same data
        if(currentNode->data == nextNode->data){
            // Remove the second node
            
            // update current node's next
            currentNode->next = nextNode->next;
            
            // delete next node
            free(nextNode);
            
            // Update next node pointer too where current node is pointing
            nextNode = currentNode->next;
        }else{
            // The two nodes have different data
            // update the two node pointers
            currentNode = nextNode;
            nextNode = currentNode->next;
        }
    }
}


// There are TWO ways to reverse a linkedlist: 1) Reverse the elements in the linkedlist, 2) Reverse the links in the linked list

/*
    For reversing the linkedlist elements, you use an additional array, which is the size of the linkedlist,
    copy all the elements of the list over to the array first.
    
    Then you scan the array from the back and insert the elements into the list from the front i.e. node 1 now has the data of last node and etc..
 
    To get the size of the list, you scan list - so loop repeated n times, The copy of the list data over to the auxillary array (i.e. additional array) takes n (because you traverse full list
    ,then copy the array data back to linkedlist takes n (you traverse list again).
    therefore, the total time taken is 3n - i.e. o(3n) -> o(n)
 
    Moreover, reversing linkedlist by reversing node data requires extra space -> i.e. the auxillary array
 */
void reversing_linkedlist_via_elements(struct Node *headptr){
    
    // Used for traversing the list
    // Need the headptr later so can't use it to scan list
    struct Node *nodeptr = headptr;
    
    // First we need to know the size of the list -> for auxillary array
    int i;
    i=0;
    while(nodeptr!=NULL){
        i++;
        nodeptr=nodeptr->next;
    }
    
    // Create an auxillary array
    int list_data[i+1];
    
    // Reset nodeptr to the first node and iterator
    nodeptr = headptr;
    i=0;
    
    // Traverse list and copy data over to the auxillary array
    while(nodeptr!=NULL){
        // copy data over
        list_data[i]=nodeptr->data;
        
        // Move nodeptr to next node and increment i
        nodeptr= nodeptr->next;
        i++;
    }
    
    // Reset nodeptr back to first node and move i to the last element in the array
    nodeptr = headptr;
    i--;
    
    // Now we copy the data in auxillary array from the back to the list
    while(nodeptr!=NULL){
        // Copy last element of array to the front of the array
        nodeptr->data = list_data[i];
        
        // Move nodeptr forward and decrement i
        nodeptr = nodeptr->next;
        i--;
    }

}

/*
    Reversing the linked list by changing the links is preferred over moving data of nodes because copying data takes times (maybe not in our current case
    because we're only changing an integer, but in other applications a node could have more data. Therefore, moving all that data will take time and space.)
 
    You can reverse a list by reversing the links between the nodes using sliding pointer method. The sliding pointer method requires 3 node pointers.
    The 3 pointers are pointing to 3 consecutive nodes in the list. The middle node's  link is changed by making point to the previous node.
    
    i.e. first nodeptr = first node, second and third are NULL at start, at each iteration the third ptr is updated to point to second, the second ptr is updated to point
    to first, and the first is updated to point to the next node --------> SLIDING POINTER
        After sliding, the middle ptr node's next is updated to point to the third node ptr, i.e. the previous node.
            This process is repeated until the first nodeptr reaches the end of the list -> i.e. end of list, you stop here
 
*/
void reversing_linkedlist_via_links(struct Node **headptr){
    
    // Declare and initialize the 3 sliding pointers
    struct Node *nextNode = *headptr;
    struct Node *currentNode = NULL, *previousNode = NULL;
    
    while(nextNode!=NULL){
        
        // Slide the three pointers first, because the *current is the node who's link is reversed to previous
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        
        // Reverse link of currentNode to the previous node
        currentNode->next = previousNode;
    }
    
    // At this point the 3 sliding pointers are as:
    // nextNode = NULL, currentNode = EndOfOriginalList, previousNode = secondLastNodeOfOriginalList
    
    // Update the headptr of the list to the new first node, which is where the currentNode is pointing.
    *headptr = currentNode;
}



void reverse_recursion(struct Node *follower, struct Node *forward, struct Node **headptr){
    
    if(forward!=NULL){
        // Not the end of the list
        // recursively move ahead of the list
        reverse_recursion(forward, forward->next, headptr);
        
        // On return, the *forward node's next should point to where the follower is pointing
        forward->next = follower;
        
    }else{
        // base case, forward = NULL, i.e. end of list reached. Therefore, follower is pointer to the last node, which should be your first node now
        *headptr = follower;
    }
}

/*
    In this method, we're reversing the list by updating the links between nodes. We're using recursion here to do this.
    We're using two pointers, one is traversing the list and the other is following it.
 
    The two pointers are moving forward at each call until the front pointer reaches NULL, at this point you update your head pointer to
    point to where the follower is pointing -> i.e. the base case for recursion
    
    Next, on return of every recursive call, the front pointer (which is ahead of the follower) will update is node's next to the node pointed to by the follower pointer.
 
    Therefore, first you move ahead recursively and then on return the links are updated
 */
void reversing_linkedlist_via_links_recursively(struct Node **headptr){
    
    struct Node *frontptr = *headptr;
    struct Node *follower = NULL;
    
    reverse_recursion(follower, frontptr, headptr);
}
