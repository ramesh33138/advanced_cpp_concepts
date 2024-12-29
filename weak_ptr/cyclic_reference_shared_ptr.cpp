#include <iostream>
#include <memory>
// To avoid memory leak in cyclic reference we are going to use shared_ptr
class Next;
class Node {
	public:
		std::shared_ptr<Next> next;

};
class Next {
	public:
		std::shared_ptr<Node> node;

};

int main(int argc, char* args[]) {
	std::shared_ptr<Node> node = std::make_shared<Node>();
	std::shared_ptr<Next> next = std::make_shared<Next>();
	//cyclic reference  
	node->next = next;//node is pointing to next
	next->node = node;//next is pointing to node
	
	return 0;
}
