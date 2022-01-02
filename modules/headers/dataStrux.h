/*
Defines some commonly used template classes.

*/

#include <stdlib.h>
#include <stdio.h>
#define DATA_STRUCTURES

extern int debug;

//doubly-linked list
typedef struct LINKED_LIST_NODE {
  struct LINKED_LIST_NODE* prev;
  struct LINKED_LIST_NODE* next;
  void* payload; //function pointer
} Node;

//Basically just a constructor
Node* MakeNode()
{
    Node* outputNode = (Node*)(malloc(sizeof(Node)));
    outputNode->prev = NULL;
    outputNode->next = NULL;
    return outputNode;
}

//Setters
void SetNextNode(Node* src, Node* next)
{
  if (src)
  {
  src->next = next;
  }
  if (next) {next->prev = src;}
}

void SetPrevNode(Node* src, Node* prev)
{
  Node* oldPrev = NULL;
  if (src) {
    oldPrev = src->prev;
    src->prev = prev;
  }
  if (prev) {
    prev->prev = oldPrev;
    prev->next = src;
  }
}

//Memory Cleanup
void DeleteNodes(Node* head)
{
  //If in debug mode, print the current address
  if (debug)
  {
    printf("Current Address: %lx\n", (long unsigned)head);
  }

  //Return if the input pointer is null
  if (head == NULL){
    return;
  }

  //Recursive call to next node
  if (head->next != NULL)
  {
    if (debug)
    {
      printf("Next Address: %lx\n",(long unsigned)(head->next));
    }
    DeleteNodes(head->next);
  }

  //Set pointers to NULL to avoid data leaks
  head->next = NULL;
  head->prev = NULL;
  free(head);

}
