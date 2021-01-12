/* Not sure if the marbles are supposed to be indivdual things. If so, then I will change my code to reflect that
such as creating a list or array called bag that will add the number of marbles to it via user input. So if I had
an empty bag of marbles and the user wanted to add 5 marbles, maybe it would look something like:
{0, 0, 0, 0, 0} indicating there are 5 marbles in the bag now. Or perhaps each element is an integer e.g. {12,13,14} 
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;


int main ()
{
   int bag = 0;
   for(;;){
       int input_number = 0;
       int choice;
       cout << "Would you like to: " << endl;
       cout << "1: Add marbles." << endl;
       cout << "2: Remove marbles." << endl;
       cout << "3: Exit." << endl << endl;
       cin >> choice;
       cout << endl;

       if(choice != 1 && choice != 2 && choice != 3){
          cout << "Not a valid input, please try again" << endl << endl;
       }
       
       else if(choice == 1){
           cout << "How many marbles would you like to add? ";
           cin >> input_number;
           cout << endl;
           bag = bag + input_number;
           cout << "There are now " << bag << " marbles." << endl << endl;
       }
        else if(bag == 0 && choice == 2){
              cout << "Sorry, there are no marbles in the bag." << endl << endl;
           }
        else if(choice == 2){
           cout << "How many marbles would you like to remove? ";
           cin >> input_number;
           cout << endl;
           bag = bag - input_number;
           cout << "There are now " << bag << " marbles." << endl << endl;
        }
        else if(choice == 3){
           break;
        }
   }
    return 0;
}
