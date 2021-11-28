#include <iostream>
#include <string>
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

void menu();
void insert_msg();
void delete_msg();
template <class T>
void printOrder(T&);// This is a way to creat a function pointer

int main()
{
   void (*visit)(int&) = printOrder;
   string input = "";
   bool exit_now = false;
   BinarySearchTree<int> stree;
   while (!exit_now)
   {
      menu();
      getline(cin, input);
      if (input == "i") // This calls Incrametal 
      {
         insert_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.insert(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "r") // this removes One node 
      {
         delete_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.remove(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "c") // Clear Tree 
         stree.clear();
      else if (input == "t") //Print Tree
         stree.print();
      else if (input == "h") // Prints tree Height
         cout << "\nThe height of the binary tree is " << stree.height() << endl;
      else if (input == "s") // Print Tree Size
         cout << "\nThe size (node count) of the binary tree is " << stree.size() << endl;
      else if(input == "m") // Pre-Order They all need to take inputs 
      {
         cout << "\n The Pre-order traversal of the tree."; 
         stree.preorder(printOrder);
      }
      else if (input == "n")// In-order
      {
         cout << "\n The In-order Traversal of the tree."; 
         stree.inorder(printOrder);
      }
      else if (input == "p") // Post-Order
      {
         cout << "\n This is for the Post-Order traversal of the tree."; 
         stree.postorder(printOrder);
      }
      else if (input == "l") // Leaf Count
         cout << "\nThe number of leafs in a binary tree is " << stree.leaf() << endl;
      else if (input == "e")
         cout << "\nThis is the operation=().";
      else if (input == "x")
         exit_now = true;
   }
}

void menu()
{
   cout << "\n";
   cout << "***********************\n";
   cout << "Menu:\n";
   cout << "i. Incremental Insert\n";
   cout << "r. Incremental Remove\n";
   cout << "c. Clear tree\n";
   cout << "t. Print tree\n";
   cout << "h. Print tree height\n";
   cout << "s. Print tree size\n";
   cout << "m. The Pre-order traversal of the tree.\n";
   cout << "n. The In-order Traversal of the tree.\n";
   cout << "p. This is for the Post-Order traversal of the tree.\n";
   cout << "l. print out number of leafs in the tree\n";
   cout << "x. Exit\n";
   cout << "***********************\n";
}

void insert_msg()
{
   cout << "\nEnter new integer keys to insert.  Enter \"q<Enter>\" to quit.\n\n";
}

void delete_msg()
{
   cout << "\nEnter integer keys to delete.  Enter \"q<Enter>\" to quit.\n\n";
}

template <class T>
void printOrder(T& data)
{
   cout << data << endl;
}