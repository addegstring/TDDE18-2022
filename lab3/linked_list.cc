#include <iostream>
#include <string>
#include <iomanip>
#include "linked_list.h"

using namespace std;

bool Sorted_List::is_empty() const
{
  return head == nullptr; // check if empty
}

Sorted_List::~Sorted_List()
{
  while(!is_empty())
  {
    //pop();
    return;
  }
}

void Sorted_List::remove(int value1)
{
  if(is_empty())
  {
    return;
  }

  Node* curr{head}; //current 'position'
  Node* prev{nullptr}; //previous 'position'
  if (curr != nullptr && curr->value == value1){
  head = curr->next;
  delete curr;
  } else{
    while(curr != nullptr && curr->value != value1){//look through the list for a match
      prev = curr; //assigning for next iteration
      curr = curr->next;
    }
    //if (curr == nullptr){
      //return;
    //}
    prev->next = curr->next; //assigning for next iteration

    delete curr;
  }

}

void Sorted_List::insert(int value)
{
  if (is_empty())
  { // if head is nullptr create new node
    head = new Node{value, head};
  }
  else
  {
    Node *curr{head}; // else construct curr as node pointer head

    if (curr->value > value)
    { // if the value curr is pointing to is less then inserted value create new node
      head = new Node{value, head};
    }
    else if (curr->value < value)
    {
      if (curr->next == nullptr)
      { // in case of nullptr current->next becomes a new node
        curr->next = new Node{value, curr->next};
      }
      else
      {
        insert(value, curr); // else go to second insert function
      }
    }
  }
}


void Sorted_List::insert(int value, Sorted_List::Node *curr)
{ // recursive insert function with pointer, for sorting

  if (curr->next->value > value) 
  {
    curr->next = new Node{value, curr->next};
  }
  else if (curr->next->value < value)
  {
    if (curr->next->next == nullptr)
    {
      curr->next->next = new Node{value, curr->next->next};
    }
    else
    {
      curr = curr->next;
      insert(value, curr);
    }
  }
}

string Sorted_List::print_list() const
{
  std::stringstream ss{};
  Node *tmp{head}; // temporary pointer of head
  while (tmp != nullptr)
  {
    ss << (tmp->value) << "->";
    tmp = tmp->next;
  }
  ss << "end\n";
  return ss.str();
}

/*Sorted_List Sorted_List::&operator=(Sorted_List const& original)
{

}
*/
Sorted_List::Sorted_List()
    : head(nullptr)
{
}