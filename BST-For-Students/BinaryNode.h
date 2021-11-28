#ifndef BINARYNODE_H
#define BINARYNODE_H
template <class T>
struct BinaryNode{
//    data members:
   T data;
   BinaryNode<T> *left;
   BinaryNode<T> *right;
//    constructors:
   BinaryNode();
   BinaryNode(const T&);

  
};

template <class T>
BinaryNode<T>::BinaryNode()
{
   left = right = nullptr;
}

template <class T>
BinaryNode<T>::BinaryNode(const T &x)
{
   data = x;
   left = right = nullptr;
}
#endif
