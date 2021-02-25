/* Note: The following implementation of Queue with Stacks is with Dequeuing the costly operation - 
        i.e. dequeuing takes longer than enqueuing because new element pushed into Stack will be at the bottom of the 
            stack - simple push() to enqueue new elements. 
            However, to dequeue first element: 
                1. Need to empty stack one by one to a new stack(temporary storage)
                2. pop the top of new stack -> your first element
                3. Move the temporary stack elements back to original stack 
*/
class  Queue{
    Stack s1, s2;    // Need two stacks of equal size to implement Queue with Stacks; s1 for holding the data and s2 as temporary storage for data operations
    public:
    void enqueue(int x);
    int dequeue();
    void display();

};