#include "BST.h"

 node::node(int num):value(num),left(nullptr),right(nullptr){};

/* int count;
 int (*compare) (void* argu1, void* argu2);
 node* root;  //first node
 */
 BST::BST():count(0),root(nullptr){};
 BST::~BST(){
    if (root == nullptr) {
        return;
    }
    vector<node*> v;
    node* current = root;
    while (v.empty() == 0 || current != nullptr) {
        if (current != nullptr) {
            v.push_back(current);
            current = current->left;
        } else {
            node* prev = v.back();
            v.pop_back();
            delete prev;
            current = prev->right;
        }
    }
 };
 bool BST::BST_Insert(void* dataPtr){
   int num = *static_cast<int*>(dataPtr);
   node* current = root;
   node* newnode = new node(num);
   node* prev = nullptr;
   while (current != nullptr){
     if (num < current->value){
       prev = current;
       current = current->left;
     }
     else if (num > current->value){
       prev = current;
       current = current->right;
     }
   }
   count += 1;
   if (prev == nullptr){
     root = newnode;
     return 1;
   }
   if (num < prev->value)
       prev->left = newnode;
   else if (num > prev->value)
       prev->right = newnode;
   return 1;
 };
 bool BST::BST_Delete(void* dltKey){
    int num = *static_cast<int*>(dltKey);
    node* current = root;
    node* prev = nullptr;
    while (current && current->value != num){
     if (num < current->value){
       prev = current;
       current = current->left;
     }
     else if (num > current->value){
       prev = current;
       current = current->right;
     }
   }
   if (current == nullptr){
    cout << "The number is not in BST." << endl;
    return 0;
   }
   if (count == 1){
      count --;
      return 1;
   }
   if (current->left == nullptr && current->right == nullptr){
        delete current;
        if (num < prev->value)prev->left = nullptr;
        else prev->right = nullptr;
   }

   else if (current->left && current->right){
        node* nextinline = current->right;
        node* nprev = current;
        if (current->right->left == nullptr){
            current->value = nextinline->value;
            delete nextinline;
            current->right = nullptr;
        }
        while(nextinline->left){
            nprev = nextinline;
            nextinline = nextinline->left; 
        }
        current->value = nextinline->value;
        delete nextinline;
        nprev->left = nullptr;
   }

   else{
        if (current->left){
            current->value = current->left->value;
            delete current->left;
            current->left = nullptr;
        }
        else{
             current->value = current->right->value;
            delete current->right;
            current->right = nullptr;
        }
   }
   count-= 1;
   return 1;
 };
 void BST::BST_Traverse(void (*process) (void* dataPtr)){
   if (root == nullptr) {
        return;
    }
    vector<node*> v;
    node* current = root;
    while (v.empty() == 0 || current != nullptr) {
        if (current != nullptr) {
            v.push_back(current);
            current = current->left;
        } else {
            node* prev = v.back();
            v.pop_back();
            if (prev) (*process)(prev);
            current = prev->right;
        }
    }
 }
 
 
 
 //a func ptr that points to a func who takes a void ptr as input
 bool BST::BST_Empty(){
    if(count == 0) return 1;
    else return 0;
 };
 bool BST::BST_Full(){
   bool Full = true;
   Full = check_full(root);
   return Full;
 };
 int BST::BST_Count(){
    return count;  
 }
  
 bool BST::check_full(void* dataPtr){
   node* current = static_cast<node*>(dataPtr);
   if (current == nullptr)
     return true;
   check_full(current->left);
 
   if ( (current->left == nullptr && current->right != nullptr) || (current->left != nullptr && current->right == nullptr))
     return false;
     
   return check_full(current->left) && check_full(current->right);
 }
 
 //node* BST::_insert(node* root, node* newPtr); //Call by BST_Insert

 void BST::free_mem(void* dataPtr){
    delete static_cast<node*>(dataPtr);
 }
 //Add more function members here





/*struct node{
 void* dataPtr;
 node* left;
 node* right;
 int value
 node(int);
};*/
