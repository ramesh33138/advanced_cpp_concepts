#include <iostream>
class Next;
class Node {
	public:
		Next* next;
		Node(){}
		~Node(){
			delete next;
			std::cout<<"next is deleted"<<std::endl;
		}

};
class Next {
	public:
		Node* node;
		Next(){}
		~Next(){
			delete node;
			std::cout<<"next is deleted"<<std::endl;
		}

};

int main(int argc, char* args[]) {
	Node* node = new Node();
	Next* next = new Next();
	//cyclic reference  
	node->next = next;//node is pointing to next
	next->node = node;//next is pointing to node
	
	// // Memory leak occurs because both node and next will delete each other, but the memory for them
    // is not properly deallocated.
	delete node;//This deletes node, but next is not deleted correctly because A tries to delete it.
	delete next;//similarly it deletes next not node.
	return 0;
}
