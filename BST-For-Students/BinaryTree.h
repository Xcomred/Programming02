#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <math.h>
#include "BinaryNode.h"
using namespace std;


template <class T>
class BinaryTree 
{
public:
   BinaryTree();
   ~BinaryTree();
   bool empty() const;
   void preorder(void (*visit)(T &)); //What our we visting? Why is it here? 
   void inorder(void (*visit)(T &));
   void postorder(void (*visit)(T &));
   int size() const;
   void clear();
   int leaf() const;
   int height() const;
   void print() const; // A method to print out the tree using preorder
   BinaryTree& operator=(const BinaryTree<T>&);// Adding it to public Calling the class as a pointer
   // Needs to be constant as when we send the data to Copy clear we need it to Copy it.


   //Add the prototypes of the Big-Three below and add their definitions later

protected:
   // Auxiliary functions
   void recursive_preorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_inorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_postorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   int recursive_size(BinaryNode<T>* sub_root) const;
   void recursive_clear(BinaryNode<T>* sub_root);
   int recursive_height(BinaryNode<T>* sub_root) const;
   BinaryNode<T>* recursive_copy(BinaryNode<T>* sub_root);
   int recursive_leaf_count(BinaryNode<T>* sub_root) const;
   void recursive_preorder_print_node(BinaryNode<T>* sub_root) const;
   
   // Data member
   BinaryNode<T>* root;

  
};

template <class T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
   clear();
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& copy) // Needs to be in the class to be accessed 
{
      copy = recursive_copy(root->data);
      return copy;

}
template <class T>
bool BinaryTree<T>::empty() const
/*
      Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   return (root == nullptr);
}

template <class T>
void BinaryTree<T>::preorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_preorder( root, visit);
}

template <class T>
void BinaryTree<T>::inorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_inorder(root, visit); // orgianlly had recursive_inorder(visit(int&), root->data);
}
template <class T>
int BinaryTree<T>::leaf() const
{
   int LEAFyishere = recursive_leaf_count(root);
   return LEAFyishere;  // can't just pass a local data 
}

template <class T>
void BinaryTree<T>::postorder(void (*visit)(T &))// We pass object and a Pointer So the tree 
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_postorder( root, visit);// We do this for added secuirty its a way to protect where the node is actaully created.
}
// just root your just passing the node Not the Data which is a int
template <class T>
int BinaryTree<T>::size() const
/* 
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
   int size = recursive_size(root);// Trying retuern root rather than return root->data
   return size;
}


template <class T>
void BinaryTree<T>::clear()
/* 
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
   recursive_clear(root);
}

template <class T>
int BinaryTree<T>::height() const
/* 
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
   int localHeight = recursive_height(root);
   return localHeight;
}


template <class T>
void BinaryTree<T>::print() const
{
/* 
Post: The tree has been traversed in preorder.  Each node and its two children is printed 
Uses: The function recursive_preorder_print_node
*/
   cout << endl;
   cout << "++++++++++++++++++++++" << endl;
   if(root == nullptr)
      cout << "EMPTY TREE" << endl;
   else{
      if(root->left == nullptr && root->right == nullptr)
         cout << root->data << ":  -  -" << endl;// No member named key KEY bad data good

      recursive_preorder_print_node(root);
   }
   cout << "++++++++++++++++++++++" << endl;
   cout << endl;
}

// Functions

template <class T>
void BinaryTree<T>::recursive_preorder(BinaryNode<T>* sub_root, void (*visit)(T& )) 
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
V left right 
*/
{
   if(sub_root != nullptr)
   {
      visit(root->data);
      recursive_preorder(sub_root->left, visit);
      recursive_preorder(sub_root->right, visit);
   }
   
}

template <class T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root, void (*visit)(T &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
Furthest to the left. 
left, V , right 
*/
{
   if(sub_root != nullptr)
   {
      recursive_inorder(sub_root->left, visit);
      visit(root->data);
      recursive_inorder(sub_root->right, visit);
   }
}

template <class T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root, void (*visit)(T &))
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively.
Goes left, right , V
*/
{
   if(sub_root != nullptr)
   {
      recursive_postorder(sub_root->left, visit);
      recursive_postorder(sub_root->right, visit);
      visit(root->data);
   }
}

template <class T>
int BinaryTree<T>::recursive_size(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
   if(sub_root == nullptr)
   {
      return 0;
   }
   else
   {
      int ls = recursive_size(sub_root->left);
      int rs = recursive_size(sub_root->right);
      return 1 + ls + rs;
   }
}

template <class T>
void BinaryTree<T>::recursive_clear(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{
   // we our going to traverse the node and remove the data through each side of the tree. 
   BinaryNode<T> *rootToBeDeleted = sub_root;
   if(sub_root == nullptr)
   {  
      return;
   }
   rootToBeDeleted->data = sub_root->data;

   if ((sub_root->left != nullptr)||(sub_root->right != nullptr)) // Using or or to just say hey lets look to see if we have 2 nodes
   {
     // We make our first copy 1 copy made. Ie 1 Spell on the stack
      rootToBeDeleted = recursive_clear(sub_root->left); // We travere to the left now we start back at the top and we have 2 spells on the stack
      rootToBeDeleted =recursive_clear(sub_root->right);
   }
   delete rootToBeDeleted;// had remove this as its not a member of the class
   sub_root = nullptr;
}
   /* Prior code that did not work
   if(sub_root->left != nullptr)
   {
      root = recursive_clear(sub_root->left);
   }
   if (sub_root->right != nullptr)
   {
      root = recursive_clear(sub_root->right);
   }
   */

template <class T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const 
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
   
   if(sub_root == nullptr)
   {
     return 0;
   }
   else
   {
      int Lheight = recursive_height(sub_root->left);
      int Rheight = recursive_height(sub_root->right);
      return max(Lheight, Rheight) + 1;
   } 
}   

/*  old vershion new one more efficient   
else if(sub_root->left != nullptr)
   {
      recursive_height(sub_root->right);
      height++;
   }
   else if(sub_root->right != nullptr)
   {
      recursive_height(sub_root->right);
      rightHeight++;
   }
   if(height > rightHeight)
   {
      return height + 1;  
   }
   else
   {
      height = rightHeight;
      return height + 1;
   }*/

template <class T>
BinaryNode<T>* BinaryTree<T>::recursive_copy(BinaryNode<T>* sub_root) // If I add Another node when i call the class I can traverse twice
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
   if(sub_root == nullptr){
      return 0;
   }
   BinaryNode<T>* copy_root = new BinaryNode<T>;
   // needs to be in else. 
   //sub_root =  copy_root; //  Sets the first value in the List to this new root. 
   copy_root->value = sub_root->value; // we our not traversing two nodes just traversing the main node and making copies. 
   copy_root->data = recursive_copy(sub_root->left); 
   copy_root->data = recursive_copy(sub_root->right); 
   

   return copy_root->data;

}

template <class T>
void BinaryTree<T>::recursive_preorder_print_node(BinaryNode<T> *sub_root) const // do we send In order out order 
/*
Pre:  sub_root is either nullptr or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != nullptr) {
      if(sub_root->left != nullptr || sub_root->right != nullptr){
         cout << sub_root->data << ":  ";
         if(sub_root->left != nullptr)
            cout << sub_root->left->data << "  ";
         else
            cout << "-  "; // "-" represents no child
         if(sub_root->right != nullptr)
            cout << sub_root->right->data << " ";
         else
            cout << "-  "; // "-" represents no child
         cout << endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}
// kept calling and setting to zero again
template <class T>
int BinaryTree<T>::recursive_leaf_count(BinaryNode<T> *sub_root) const
{
   
    if(sub_root == nullptr)    
        return 0;
    if(sub_root->left == nullptr && sub_root->right == nullptr)
        return 1;        
    else
        return getLeafCount(sub_root->left) + getLeafCount(sub_root->right);
}
#endif
/*   else if(sub_root->left != nullptr )
   {
       recursive_leaf_count(sub_root ->left);

   }else if(sub_root->right != nullptr)
   {
      recursive_leaf_count(sub_root ->left);
   }
   else if((sub_root->left == nullptr)&&(sub_root->right == nullptr))
   {
         leafCount++;
   }*/