# Based on what we know about linked lists, stacks, and queues, design a queue data structure:
## What functions are we likely to need for a queue to function like the one discussed in class?
We will need a enqueue function which will take a value and insert it at the tail or rear end of the queue. We will also need a dequeue function which will take a value and delete the value at the front of the queue, and it will also return the element at the front of the queue. Another function could be the peek function, which will simply look at the element that is in the front of the queue and returns it.  


## What values will we need to know about the structure for our queue to function properly?
We will need to know the value of what is being added or deleted. Other values that we will keep track of are the front and rear pointers. The front pointer points to the front of the queue, as the name implies, and the rear points to the rear of the queue. When we first add an element to the empty queue, the front and rear pointer will be pointing to the same node. When the dequeue function is used, it should delete the front node and advance the front pointer to the next node.


# Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):
## What functions are we likely to need for a list to function like this?
We will want an insert function which will insert value at indicated index if it exists, will start at the head and iterate through each nodes next pointer whilst decrementing the index each time until the index is full. We will also want a remove function, which will start pointing to nothing at first, then make a temp pointer, then have the current pointer point to the same thing that the head is pointing to, this will make it so the head pointer is always pointing to the beginning of the list. Then we'll check if the current node is the one we want to delete, and if it is we delete it, if it isn't then we advance the current pointer and have the temp pointer trail behind so we can be able to patch up the list when we do delete a node.


# What values will we need to know about the structure for our list to function properly?
We will need a node structure with a variable to store data, and we will also need a next variable which points to the next node. We will also want a pointer to the first node in the linked list. Furthermore, we will want the values for the insert and remove functions.
