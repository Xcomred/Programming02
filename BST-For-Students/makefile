a.exe: main.o
	g++ main.o -o a.exe
main.o: BinaryTree.h BinaryNode.h BinarySearchTree.h  main.cpp
	g++ -c -g main.cpp
clean:
	rm* .o
	rm a.exe