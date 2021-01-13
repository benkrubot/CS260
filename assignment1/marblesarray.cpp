/* Tried creating a class and using an array instead. Unsure if I am doing any of this
correctly, new to c++.
*/

#include <iostream>
using namespace std;

class Bag 
{
    public:
        Bag();
        int     count;
        int     marble_bag[10];
        int     insert(int x);
        int     remove(int x);
};

Bag::Bag()
{
    count = 0;
}

int Bag::insert(int x) 
{
    marble_bag[count]=x;
    count++;
    return 0;
}



int Bag::remove(int x) {
    int i = 0;

    while (i<count)
    {
        if (marble_bag[i] == x) 
        {
            /* Not sure how to remove the element, so I replaced it with a 0. */
            marble_bag[i] = 0;
            break;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    Bag b;

    b.insert(12);
    b.insert(5);
    b.insert(3);
    cout << "There is a " << b.marble_bag[0] << endl;
    cout << "There is a " << b.marble_bag[1] << endl;
    b.remove(5);
    
    /* This is testing to see if 5 is being removed */
    for (int i = b.count - 1; i >= 0; i--) 
    cout << b.marble_bag[i];
}