#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/patient.h"

Node *createNode(Patient list) {
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->list.name, list.name);
    temp->list.date = list.date;
    strcpy(temp->list.month, list.month);
    temp->list.year = list.year;
    return temp;
}

void Push_Head(Patient value){
    Node *temp = createNode(value);
    if(!head){
      head = tail = temp;
    } 
    else{ 
      head->prev = temp;
      temp->next = head;
      head = temp;
    }
}

void Push_Tail(Patient value) {
  Node *temp = createNode(value);

  if(!head) { 
    head = tail = temp; 
  } 
  else {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void Push_Mid(Patient value) {
  if(!head) { 
    Node *temp = createNode(value);
    head = tail = temp;
  } 
  else if(value.year < head->list.year){ 
    Push_Head(value);
  } 
  else if(value.year > tail->list.year){ 
    Push_Tail(value);
  } 
  else{
    Node *temp = createNode(value);
    curr = head;

    while(curr->list.year < value.year) {
      curr = curr->next;
    }
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev->next = temp;
    curr->prev = temp;
  }
}

void add_patient(Patient value){
    // Patient value = (Patient*)malloc(sizeof(Patient));
    createNode(value);
    scanf("%d %s %d - %[^\n]", &value.date, value.month, &value.year, value.name);
    getchar();
    Push_Mid(value);
}

void pop_head() {
    if(head && head == tail) {
        head = tail = NULL;
        free(head);
    } 
    else {
        Node *New_Head = head->next;
        head->next = New_Head->prev = NULL;
        free(head);
        head = New_Head;
    }
}

void print_list() {
  curr = head;
  while(curr) {
    printf("%d %s %d - %s", curr->list.date, curr->list.month, curr->list.year, curr->list.name);
    curr = curr->next;
  }
  puts("");
}
