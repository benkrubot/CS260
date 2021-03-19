/*Had problems with this program but I think it works now.. this will map keys to values. Everything works correctly I think. 
*/

#include <iostream>
#include <string>
#include<list>
#include <cstring> //Key value pair will be int type and value str type
using namespace std;

//Hashtable to implement phone number and name
class HashTable{
  private:
    static const int hash_groups = 10;
    //Array to store lists, each list store pair
    list<pair<int, string>> table[hash_groups]; //List 1 is index 0
  public:
    bool isEmpty() const; //Whether data structure is empty or not
    int hash_function(int key); //Take key return int
    void insert_item(int key, string value);
    void search_for(string value); //Takes string value and searches for it
    void print_table(); //Test to make sure insert is working correctly

};

int HashTable::hash_function(int key) {
  //Want to return value between 0 and 9
  return key % hash_groups; //Key: 905, then will return 5 which will be 6th list in table
}

void HashTable::insert_item(int key, string value) {
  int hash_value = hash_function(key); //Whatever the result of this hash will signify which lists this key value pair needs to go into
  
  auto& cell = table[hash_value]; //List that we will put key value pair into which is table at given index
  
  auto bItr = begin(cell); //Iterator to beginning of list
  
  //We don't just push pair into list because we need to know whether key exists or not
  bool key_exists = false;

  //Iterate over respective list to make sure key does not exist and if it does then replace the value of that key with new value
  for (; bItr != end(cell); bItr++) {
    if (bItr -> first == key) {
      key_exists = true;
      bItr -> second = value; //Replacing value corresponding to key
      break; //Break loop since each key is distinct
    }
  }
  //Key doesn't exist
  if (!key_exists) {
    cell.emplace_back(key, value); //Push key value pair back into list, cell is list we are interested in
  }
  return;
}

void HashTable::search_for(string value) {
  int i{};
  bool x = false;
  for (; i < hash_groups; i++) { //Start at first list, have 10 lists
      if (table[i].size() == 0) continue; //If size of list at position is 0 then continue otherwise won't continue loop
      auto bItr = table[i].begin(); //Iterator points to beginning of list
      for (; bItr != table[i].end(); bItr++) { //Iterate through list
        if (bItr -> second == value) {
          cout << "The value "<< value <<" exists." << endl; //Testing to see if function works, will print if it does
          x = true;
          break;
        }
      }  
    }
  cout << x << endl; //Testing
  if (x == false) {
    cout << "The value " << value << " was not found." << endl;
  }
  return;
}

//Print function to test if insert function is working
void HashTable::print_table() {
  for (int i{}; i < hash_groups; i++) {
    if (table[i].size() == 0) continue;
    auto bItr = table[i].begin();
    for (; bItr != table[i].end(); bItr++) {
      cout << "[INFO] Key:" << bItr -> first << " Value: " << bItr -> second << endl;
    }
  }
  return;
}


int main() {
  HashTable ht;
  ht.insert_item(905, "Jim");
  ht.insert_item(441, "Haylie");
  ht.insert_item(541, "Angelina");
  ht.insert_item(993, "Coulson");
  ht.search_for("Bob");
  ht.search_for("Haylie");
  ht.search_for("Haylie");
  ht.search_for("Angelina");
  ht.search_for("Coulson");
  ht.search_for("Katelyn");
  ht.print_table();
}
