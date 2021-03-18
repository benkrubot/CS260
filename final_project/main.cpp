/* This is a program that uses an adjacency matrix to create a graph. There is a Graph function 
which is the constructor for the adjacency matrix, there is an add_edge function which takes 3 
parameters those being x, y, and z which is the edge weight. There is an add_vertex function which 
basically increases the number of vertices by 1 and adds 1 column to the adjecency matrix (all added being 0). 
There is also a simple display function that iterates through the matrix and outputs it. Next there is a mst 
function which finds the minimum spanning tree. This finds it by maintaining an array of visited vertices 
(0,1,2 etc) with values false, which will be changed to true if min value found, and if found then loop will 
go to that row. Next is the shortestpath function where we set spt that keeps track of vertices included in 
shortest path tree, then we assign distance value to all vertices in input graph and initialize all distances 
to infinity except for source which we set to 0. Then while the spt doesn't include all of the vertices, we pick 
a vertex j which is not in the spt and has a min distance value. From there we include j in spt and then we update 
distance value of vertices adjacent to j. To do so we iterate through the adjacent vertices. Then for every adjacent 
vertex i, if the sum of the distance value j from source and weight of edge j-i is less than the distance value i, we 
then update the distance value i. */

#include <iostream> 
#include <list>
#include <limits.h>
#include <cstring>
using namespace std; 
  
class Graph { 
private: 
  //This is number of vertices 
  int n; 
  //This is the adjacency matrix 
  int matrixSize = 10;
  int matrix[10][10];

public: 
  //Constructor 
  Graph(int x) 
  { 
    n = x; //Seting vertices to input
    //This will initialize each element of the adjacency matrix to zero 
    for (int i = 0; i < n; i++) { 
      for (int j = 0; j < n; j++) { 
        matrix[i][j] = 0; 
      } 
    } 
  } 
  
  //Adding edges to vertices in adjacency matrix
  void add_edge(int x, int y, int z) 
  { 
    //This checks if the vertex exists in the graph 
    if ((x >= n) || (y > n)) { 
      cout << "Sorry! Vertex does not exist!"; 
    } 
  
    //This checks if the vertex is connecting to itself 
    if (x == y) { 
      cout << "Sorry! " << x << " cannot connect to " << y << ", same vertex!" <<endl; 
    } 
    else { 
      //This will connect the vertices 
      matrix[y][x] = z; 
      matrix[x][y] = z; 
    } 
  } 

  //Adding vertex to adjacency matrix
  void add_vertex() 
  { 
    //This will increase the number of vertices 
    if (n == matrixSize) { //I set a limit so if the number of vertices = matrixSize then it will output message and return
      cout << "Sorry, you cannot add anymore." << endl;
      return;
    }
    n++; //Increase number of vertices
    int i; //Initialize
  
    //This will initialize the new elements of adjacency matrix to 0
    for (i = 0; i < n; i++) { 
      matrix[i][n - 1] = 0; 
      matrix[n - 1][i] = 0; 
    } 
  } 

  //Test to see if constructor is working/see if addEdge and addVertex are working
  void display() 
  { 
    cout << "Adjacency Matrix:"; 
    // displaying the 2D array 
    for (int i = 0; i < n; i++) { 
      cout << "\n" << endl; 
      for (int j = 0; j < n; j++) { 
        cout << "  " << matrix[i][j];
      } 
    }
    cout << "\n" << endl; 
  } 


//Minimum spanning tree function
int mst(){
  int v_array[n]; //Visited vertices
  memset(v_array,false,sizeof(v_array)); //Initialize the array with everything as false
  v_array[0] = true; //This is so we will start at the 0 vertex
  cout << "EDGE\t\t WEIGHT\n"; 
  int n_edges = 0;
  while(n_edges<n-1) { //MST definition
    int min = INT_MAX; //Variable to choose min value according to prim's algorithm
    int r = 0, c = 0; //Initializing the variables row and column used to output edge

    for(int i=0; i<n; i++){ //This will traversal along the row to pick every vertex
      if(v_array[i]){       //This will check if the picked vertex is inside the visited array
        for(int j=0; j<n; j++){ //This will traversal along the columns
          if(min>matrix[i][j]){ //If min is greater than postion, proceed
            if(!v_array[j] && matrix[i][j]){ //Stop if equal to 0, 
              min = matrix[i][j]; //Change min to value
              r = i;
              c = j;
            }
          }
        }
      }
    }
    cout << r << "-" << c  << "\t\t\t " << matrix[r][c]<<endl; //output min value and weight
    v_array[c] = true; //Set true for visited then going to visit that row
    n_edges++; //

  }
  return 0;
}

//This function will find the vertex with the minimum distance from the set of vertices not in spt
int min_distance(int distance[], bool spt[]) 
  { 
    //This will initialize min value 
    int min = INT_MAX, min_index;
    
    for (int i = 0; i < n; i++) 
      if (spt[i] == false && distance[i] <= min) 
        min = distance[i], min_index = i; 
    //cout << min <<endl;
    return min_index; 
  } 
    
//Function for finding shortest path, takes source and destination
void shortest_path(int src, int destination) 
{ 
  int distance[n]; //This array will hold the shortest distance from whatever source we set to n
  
  bool spt[n]; //This will be true if vertex n is included in shortest path tree or shortest distance from the source to n is finalized
  
  //This loop will initialize all distances or upperbound as INFINITE and stp[] as false
  for (int i = 0; i < n; i++) 
    distance[i] = INT_MAX, spt[i] = false; 
  
  //Distance of source vertex from itself is always 0 so that we start with it (upperbound for src is now 0 instead of infinity)
  distance[src] = 0; 
  
  //Here we are finding the shortest path for all vertices 
  for (int count = 0; count < n - 1; count++) { 
    //Now pick the minimum distance vertex from the set of vertices not yet processed. j is always equal to src in the first iteration because we set it to 0 
    int j = min_distance(distance, spt); 
  
    spt[j] = true; //This will mark the vertex as processed
  
    //This loop will update distance value of the adjacent vertices of the picked vertex 
    for (int i = 0; i < n; i++) 
  
      /*This will update distance[i] only if is not in shortest path tree, there is an edge 
      from j to i, and total weight of path from source to i through u is smaller than the 
      current value of distance[i]*/
      if (!spt[i] && matrix[j][i] && distance[j] != INT_MAX 
        && distance[j] + matrix[j][i] < distance[i]) 
        distance[i] = distance[j] + matrix[j][i]; 
  } 
  
  //Reporting the result
  cout<<"Distance from " << src << " to " << destination << " is: " << distance[destination] << "\n" << endl;
}

};


int main() 
{ 
  Graph g(6); 
  //int source_vertex = 0;
  g.add_edge(0,1,4);
  g.add_edge(0,2,3);
  g.add_edge(1,2,1);
  g.add_edge(1,3,2);
  g.add_edge(2,3,4);
  g.add_edge(3,4,2);
  g.add_edge(4,5,6);
  //g.add_edge(4,2,1); //Testing

  g.display();
  
  //cout << g.matrix[0][1] << endl;

  g.shortest_path(0,4);
  

  /*Original tree: 
   
          2
     [1]----[3]
   4/ |     /|
   /  |   4/ |
[0]   |1  /  |2  [5]
   \  |  /   |  /
   3\ | /    | /6
     [2]    [4]
  */

  /* MST:


    [1]----[3]
     |      |
     |      |
[0]  |      |   [5]
   \ |      |  /
    \|      | /
    [2]    [4] 
  */
  
  g.mst();
  return 0;
} 
