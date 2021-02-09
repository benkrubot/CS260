/* At first I had it as size = 0 and when you added an integer it will just add at the first index and as you add more it will subsequently 
add after the previous. But since the requirements were to add at certain indexes, I changed the size to 10 to allow for adding at a chosen 
index in that range. I also changed the add function and added another add_next function which increases the size by 1 and then adds the 
number at that index. At the moment you're only able to add at a certain index if it's within the size-1 e.g. size = 10 then you can add at 
any index 0-9 and as you increment the size then you can change those indexes. I guess I am trying to say that the index has to exist for it 
to be changed? Anyways not sure if what I implemented is correct but it sort of works. Interested to see how I am supposed to go about this, 
as I had many troubles doing this assignment. */

#include <iostream>

using namespace std;

class myarr
{
private:
  int cap;
  int size;
  int *arr;

  void initialize(int from)
  {
    for (size_t i = from; i < cap; i++)
    {
      arr[i] = 0;
    }
  }

  // Expand the capacity of the array
  void expand()
  {
    cap *= 2;
    int *temparr = new int[cap];
    for (size_t i = 0; i < size; i++)
    {
      temparr[i] = arr[i];
    }
    delete[] arr;
    arr = temparr;
    initialize(size);
  }

public:
  myarr()
  {
    cap = 10;
    size = 10;
    arr = new int[cap];
  }

  ~myarr()
  {
    delete[]arr;
  }

  // Function to add at an index
  void add(int item, int index)
  {
    if (size >= cap)
    {
      expand();
    }
    arr[index] = item;
  }

  // Function to increase the size by 1, and add at that index
  void add_next(int item)
  {
    if (size >= cap)
    {
      expand();
    }
    arr[size++] = item;
  }
  
  // Function to get the number at the index
  int get(int index)
  {
    if (index < 0 || index >= size)
    {
      throw("Out of bounds exception!");
    }
    return arr[index];
  }

  // Function to replace the number at index with 0
  void deleteElement(int index) 
  {
    arr[index] = 0;
  }

};

int main()
{
  myarr arr;
  cout<< "At first you may add at indexes 0-9."<<endl;
  cout<< "To increase the index by 1, use the add_next method."<<endl;
  cout<< "Once the index has been created, you may change it."<<endl;
  

  arr.add(10,5);
  arr.add(12,9);
  arr.add(13,1);
  arr.add(22,3);
  
  arr.add_next(55); // This just increases the array size by 1 and adds the number to the index
  arr.add_next(99);

  arr.add(49,11);
  
  cout<< arr.get(1)<<endl;
  cout<< arr.get(9)<<endl;
  cout<< arr.get(1)<<endl;
  cout<< arr.get(3)<<endl;
  
  cout<< arr.get(10)<<endl;
  cout<< arr.get(11)<<endl;

  arr.deleteElement(1);
  arr.deleteElement(9);

  cout<< arr.get(2)<<endl;

  cout<< arr.get(1)<<endl;
  cout<< arr.get(9)<<endl;
}
