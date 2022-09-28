#include "linked_list.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
Sorted_List list{};
Sorted_List list2{};
list.insert(9);
list.insert(10);
list.insert(8);
list.insert(12);
std::cout << list.print_list();
list.remove(9);
std::cout<< list.print_list();
list2.insert(5);
list2.insert(-2);
std::cout<< list2.print_list();
list.remove(5);
std::cout<< list2.print_list();
//ist2 = list;
list2.clear_list();
std::cout << list2.print_list() << list.print_list();
return 0;
}
