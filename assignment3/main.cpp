/*Followed a few guides, but I think i understand it pretty well unless I implemented it wrong. We create our empty queue, and in the enqueue function the new 
linked list node is created, and if the queue is empty then the new node that is added is both the front and rear. From there, we add new nodes, and each time 
we do so we advance the rear pointer to the next node. For the dequeue method, this will remove the front node and advance the pointer to the next node. If the 
queue is empty it will return null. */

#include <iostream>

using namespace std; 

struct node { 
  int data;   //Value to be stored
  node* next; //Ensures that you've a variable next which is a pointer to the node
  node(int x) //Initialize
  { 
    data = x; 
    next = NULL; 
  } 
}; 

//Creates empty queue
struct queue { 
  node *front;
  node *rear;
  queue() 
  { 
    front = rear = NULL; 
  } 
  
  //This will add a new node after the rear pointer and moves the rear pointer to the next node.
  void enqueue(int x) 
  {
  
    //This creates a new linked list node 
    node* temp = new node(x); 
  
    //If the queue is empty, then new node is both front and rear 
    if (rear == NULL) { 
      front = rear = temp; 
      return; 
    } 
  
    //This adds the new node at the end of queue and changes the rear 
    rear->next = temp; 
    rear = temp; 
  } 
  
  //This will remove the front node and move the front pointer to the next node.
  int dequeue() 
  { 
    //If the queue is empty, return 0. 
    if (front == NULL) 
      return 0;
  
    //This stores the previous front pointer and moves front to the next node. 
    int n = front->data;              //Storing node data
    cout<<n<<" was removed."<<endl;   //Displaying what is being removed
    node* temp = front;               //Store address of current node trying to delete in a temp pointer to node
    front = front->next;              //Advancing front pointer to next
  
    //If the front becomes null, then this will change the rear to null as well
    if (front == NULL) 
      rear = NULL; 
    delete (temp); //Deleting the node
    return(n);     //Returning node data that was deleted
  } 

  //Returning front element of queue
  int peek()
  {
    if (front == NULL)
      return 0;
    else
    {
      int n = front->data;
      cout<<n<<endl;
      return(n);
    }
  }

  void testdequeue()
  {
    cout<<front->data<<endl;
  }

  void testenqueue()
  {
    cout<<rear->data<<endl;
  }

  void testpeek()
  {
    cout<<front->data<<endl;
  }
}; 

//Driver
int main() 
{
  //Testing the enqueue and dequeue functions as well as pointers
  queue linkedlist; 
  
  linkedlist.dequeue();     //Returns 0, empty
  linkedlist.enqueue(10); 
  cout << "Front of queue is: " << (linkedlist.front)->data << endl;

  linkedlist.enqueue(20); 
  cout << "Front of queue is: " << (linkedlist.front)->data << endl;

  linkedlist.dequeue(); 
  linkedlist.testdequeue(); //Testing to see if dequeue removed 10, this will cout the new front which is 20
  cout << "Front of queue is: " << (linkedlist.front)->data << endl;

  linkedlist.dequeue();
  linkedlist.enqueue(30);
  cout << "Front of queue is: " << (linkedlist.front)->data << endl; 

  linkedlist.enqueue(40);
  linkedlist.testenqueue(); //Testing to see if enqueue added to the rear, this will cout the rear which is 40 
  cout << "Front of queue is: " << (linkedlist.front)->data << endl;

  linkedlist.enqueue(50); 
  cout << "Front of queue is: " << (linkedlist.front)->data << endl;

  linkedlist.dequeue();
  cout << "Front of queue is: " << (linkedlist.front)->data << endl; 
  cout << "Rear of queue is: " << (linkedlist.rear)->data << endl; 

  linkedlist.testpeek(); //Testing to see if peek returns the same value, this will cout the front which is 40
  linkedlist.peek();

}
