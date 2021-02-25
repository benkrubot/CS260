/*Took my a bit to get this running, had to catch myself up with a lot of youtube and stackoverflow due to being behind and not being able to work on this 
because of having covid.

For this program I have 4 functions. One function is to find the minimum in a tree which is used to find the replacement value when I delete a node. The 
second is the delete function, which should work recursively. It searches the tree for the value to be deleted, and then checks 3 cases to determine the 
correct solution. No children is the easiest, as well as one child, with two children being the hardest, and this is where the searchMin function solves it. 
It will find the min value on the right side of the node that is being deleted, and replace the node being deleted with the min value, then delete the duplicate. 
Next there is the inorder function which visits the left subtree, prints it, then vists the right subtree. Lastly, there is the insert function which will correctly 
insert the value, checking if the value is <= or >= the root value and then inserting it either to the left or the right. */

#include<iostream>
using namespace std;

struct node {
	int data;    //Store data
	node *left;  //Pointers to node
	node *right; //Pointers to node
};

//This is a function to find minimum in a tree. This will be used for case 3 in the delete function. 
node* searchMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// This is a function to search and delete a value from tree. Takes pointer to root node and the data to be deleted.
node* deleteVal(node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = deleteVal(root->left,data);    //Recursive call
	else if (data > root->data) root->right = deleteVal(root->right,data); //Recursive call
	//Found value, now will check if it is a leaf, has 1 child or 2 children
	else {
		//Case 1: No children, it is a leaf and will simply just be deleted
		if(root->left == NULL && root->right == NULL) { 
			delete root; //Wipe node from memory
			root = NULL;
		}
		//Case 2: One child, this will if left child is null 
		else if(root->left == NULL) {
			node *temp = root;        //Store address of current node trying to delete in a temp pointer to node
			root = root->right;       //Move pointer to right child, and now right child becomes the root of this subtree
			delete temp;              //Delete the node that has been pointed to by temp
		}
    //This will do the same as above but if right child is null
		else if(root->right == NULL) {
			node *temp = root; 
			root = root->left;
			delete temp;
		}
		//Case 3: 2 children, this will find the min in the right subtree, copy the value in targetted node, then delete the duplicate from the right subtree
		else { 
			node *temp = searchMin(root->right); //Search for min element in right subtree of the node we're trying to delete. Collecting the return in a pointer to the node named temp.
			root->data = temp->data;             //Set the data in current node trying to delete as the min value
			root->right = deleteVal(root->right,temp->data);
		}
	}
	return root;
}
 
//This is a function to insert node. Takes address of the root node as well as the data to be inserted.
node* insert(node *root, int data) {
	if(root == NULL) {   //Empty tree
		root = new node(); //Root is null so a new node will be created
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) //If this is true, make a recursive call to insert data in the left subtree
		root->left = insert(root->left,data);
	else                        //If this is true, then make a recursive call to insert data in the right subtree
		root->right = insert(root->right,data);
	return root;
}

//This is a function to visit nodes in inorder tree traversal.
void inorder(node *root) {
	if(root == NULL) return; //Exit condition
	inorder(root->left);       //Visit the left subtree
	printf("%d ",root->data);  //Print the data
	inorder(root->right);      //Visit the right subtree
}

int main() {
	/*Here we will be testing the code by creating this tree.
	         5
			   /   \
			  3     8
			 / \   / \
			1   4 6   9
    */

	node* root = NULL; //This is setting the tree as empty.
	root = insert(root,5); 
  root = insert(root,8);
	root = insert(root,3); 
  root = insert(root,4); 
	root = insert(root,1); 
  root = insert(root,6);
  root = insert(root,9);

	//Deleting node with value 5, can change this value to test other cases
	root = deleteVal(root,5);

  /*Now the tree should look like this after deleting 5:
           6
         /   \
        3     8
       / \     \
      1   4     9
    */
	
  //Printing nodes in inorder
	cout<<"Inorder traversal: ";
	inorder(root);
	cout<<"\n";
}
