#ifndef H_forward_list
#define H_forward_list

//implement the following classes
#include <iostream>
#include <memory>
#include <utility>
template <typename T>
struct Node {
	using value_type = T;
	Node(T v) : data(v) {}
	// Holds the data of the node
	value_type data;
	//Points to the next node
	Node<value_type>* next;
};

template <typename T>
struct ForwardList {
	//appends node to end of list
	void append(T v){
	if (root == nullptr){
		root = std::make_unique<Node<T>>(v);
	}else{
		Node<T> *temp;
		temp = root.get();
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = new Node<T>(v);
	}
}
	

	//Inserts node at given index. If index is greater than list size
	// decays to an append operation
	
	void insert(std::size_t i, T v){
		if(root == nullptr){
			append(v);
			std::cout<< "Now, root is nullptr, so we appended"<< std::endl;
		}else{
		int index = 0;
		Node<T> *temp;
		temp = root.get();
		while(temp->next != nullptr){
			temp = temp->next;
			index++;
		}
		if (i > index){append(v);
			std::cout<< "now, i > index, so we appended v"<<std::endl;
		}else{
			if (i == 0){
				Node<T> *temp2;
				temp2 = root.release();
				root = std::make_unique<Node<T>>(v);
				root->next = temp2;
				std::cout<< "now, we sucessfully insert a Node in Root position"<< std::endl;
			}else{
				Node<T> *temp3;
				temp3 = root.get();
				for(int j = 0; j < i - 1; j++){
					temp3 = temp3->next;
				}
				Node<T> *temp4;
				temp4 = new Node<T>(v);
				temp4->next= temp3->next;
				temp3->next = temp4;
				std::cout<< "this is a final version of inserting"<<std::endl;
			}	
			
		}
	}
}
	//Deletes the node at the given index. Doesn't do anything if the index is
	//out of range
	void remove(std::size_t i){
		int index = 0;
		Node<T> *current;
		current = root.get();
		while (current->next != nullptr){
			current = current->next;
			index++;
		}
		if(i <= index){
			if(i==0){
				std::cout << "i=0 remove\n";
				Node<T>*temp = root.release();
			       	temp = temp->next;
				root.reset(temp);
				std::cout << "i=0 remove end if\n";
			       	}else{
					std::cout << "else statement\n";
					Node<T>*temp = root.get();
					for(int j = 0; j < i - 1;j++){
					temp = temp->next;
				}	
				Node<T>* temp2;
			        temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				std::cout << "esle statement end remove\n";
			}
		}
	}


std::unique_ptr<Node<T>> root;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const ForwardList<T>& list){
	auto current = list.root.get();
	while(current != nullptr){
		os << current->data << " ";
		current = current->next;
	}
	return os;
}	
	

#endif
