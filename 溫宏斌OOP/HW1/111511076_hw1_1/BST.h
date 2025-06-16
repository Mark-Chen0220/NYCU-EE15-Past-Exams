#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
using namespace std;
struct node{
 void* dataPtr;
 node* left;
 node* right;
 int value;
 node(int);
};
class BST{
private:
 int count;
 int (*compare) (void* argu1, void* argu2);
 node* root;
public:
 //BST(int (*compare) (void* argu1, void* argu2));
 BST();
 ~BST();
 bool BST_Insert(void* dataPtr);
 bool BST_Delete(void* dltKey);
 void BST_Traverse(void (*process) (void* dataPtr));
 bool BST_Empty();
 bool BST_Full();
 int BST_Count();
 void print_BST(void* dataPtr);
 node* _insert(node* root, node* newPtr); //Call by BST_Insert
 //Add more function members here
 bool check_full(void* dataPtr);
 void free_mem(void* dataPtr);
};
#endif
