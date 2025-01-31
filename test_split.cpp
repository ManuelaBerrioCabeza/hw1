/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
  Node* node1 = new Node {9, NULL};
  Node* node2 = new Node {12, NULL};
  Node* node3 = new Node {23, NULL};
  Node* node4 = new Node{6, NULL};

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Node* testList = node1;
  Node* odds = NULL;
  Node* evens= NULL;

  split(testList, odds, evens);

  if (testList != NULL){
    return 1;
  }

  if (odds==NULL || odds->value !=9 || odds->next ==NULL || odds->next->value !=23|| odds->next->next != NULL){
    return 2;
  }

  if (evens==NULL || evens->value !=12 || evens->next ==NULL || evens->next->value !=6|| evens->next->next != NULL){
    return 3;
  }
  

  while (odds != NULL){
    Node* temp= odds;
    odds = odds->next;
    delete temp;

  }
  while (evens != NULL){
    Node* temp= evens;
    evens = evens->next;
    delete temp;
  }


  return 0;
}
