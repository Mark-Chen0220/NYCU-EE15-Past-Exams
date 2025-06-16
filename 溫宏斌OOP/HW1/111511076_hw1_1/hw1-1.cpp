// BST.h
#include "BST.h"
using namespace std;
int compareInt(void* num1, void* num2);
void printBST(void* num1);
void printMenu();
int main(){
 int option;
 BST tree;
 while(1){
  printMenu();
  cin >> option;
  int num;
  switch(option){
    case 1:
      cout << "Enter an integer: ";
      cin >> num;
      tree.BST_Insert(&num); 
      break;
    case 2:
      cout << "Enter an integer: ";
      cin >> num;
      if(tree.BST_Delete(&num)){
        if(tree.BST_Empty()) cout << "The BST is empty." << endl;
        else {
            cout << "New BST: ";
            tree.BST_Traverse(printBST);
            cout << endl;
        }
      }
      break;
    case 3:
      if (tree.BST_Empty())cout << "The BST is empty.";
      tree.BST_Traverse(printBST);
      cout << endl;
      break;
    case 4:
      if(tree.BST_Full())cout << "BST is full" << endl;
      else cout << "BST is not full yet" << endl;
      break;
    case 5:
      if (tree.BST_Empty()){
        cout << "The BST is empty." << endl;          
      }
      else{
        cout << "There are " << tree.BST_Count() << " nodes in BST." << endl;
      }       
      break;
    case 6:
      return 0;
      break;
      
    default:
      break;
  
  }
 }
 return 0;
}
/*int compareInt(void* num1, void* num2){
 //Write your own code here 
}*/
void printBST(void* num1){
   cout << static_cast<node*>(num1)->value << " ";
   return;
}
 //Write your own code here 
void printMenu(){
  cout << "The following are six options for your BST:" << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Print the BST" << endl;
  cout << "4. Check the BST is full or not" << endl;
  cout << "5. Print the number of nodes in BST" << endl;
  cout << "6. Exit" << endl;
  cout << "Please enter: ";
 //Write your own code here 
}
