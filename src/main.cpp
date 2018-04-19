#include <iostream>
#include "forward_list.h"
#include <memory>
int main(){
	ForwardList<int> list;
	std::cout<< "I created a Forward<int> list" <<std::endl;
	std::cout<< "ready test append on list.\n"<<std::endl;
	list.append(5);
	list.append(7);
	list.append(9);
	std::cout<<"after I append 5 , 7, 9. The list looks like: \n"<<list <<std::endl;
	list.append(20);
	list.append(22);
	std::cout<< "after I append 20, 22, the list looks like: \n" <<list <<std::endl;
	std::cout<< "test append finished: I appended 5,7,9, 20, and 22 on the list \n " <<std::endl;
	ForwardList<int> list2;
	std::cout<< "I build a ForwardList<int> list2 which is a new and empty list"<<std::endl;
	std::cout<< "test insert start with list2."<<std::endl;	
	std::cout<< "in the case list2.insert(5,49)" <<std::endl;
	list2.insert(5,49);
	std::cout<< "in the case list2.insert(2,26)" <<std::endl;
	list2.insert(2,26);
	std::cout<< "in the case list2.insert(0,13)"<< std::endl;
	list2.insert(0,13);
	std::cout<< "test insert on list 2: after I put command insert(5,49) and insert(2,26) and (0,13), we will get list2:\n" << list2 << std::endl;
	
	std::cout<< "now move on to original list, we are removing 3 on list" <<std::endl;
	list.remove(3);
	std::cout<< "after remove 3rd index, we get list: " << list<< std::endl;
	std::cout << "\nremoving 5 now\n";

	list.remove(5);
	std::cout <<"after removing 5, it should't change anything, now list is still: " <<list << std::endl;
}
