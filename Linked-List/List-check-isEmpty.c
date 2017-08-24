/*
 * List-isEmpty.c
 *
 *  Created on: Aug 24, 2017
 *      Author: RajeevSawant
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int data;
	struct node* next;
};

struct node *head = NULL;
void add_item(int data){
	struct node *container =  malloc (sizeof(struct node));

	container->data = data;
	container->next = head;

	head = container;
}

void print_item(){
	struct node *container = malloc (sizeof(struct node));
	container = head;
	while (container != NULL){
		printf("The value of Data is %d\n", container->data);
		container = container->next;
	}
}


void delete_item(int data){
	struct node* current_node = malloc (sizeof (struct node));

	current_node =  head;
	if (current_node != NULL && current_node->data != data){
		while (current_node->next->data != data){
			current_node = current_node->next;
		}
		current_node->next = current_node->next->next;
	}else{
		head = current_node->next;                         // If the data to be deleted is the one in the head node then make the next node as head
	}
}

bool isEmpty(){
	if (head == NULL){
		return true;
	}else{
		return false;
	}
}

int main(){
	add_item(50);
	add_item(40);
	add_item(30);
	add_item(20);
	add_item(10);

	print_item();

	printf("\n The Updated List is \n");

	delete_item(40);
	delete_item(50);
	delete_item(10);

	print_item();


	printf("\n Is the List Empty %d \n", isEmpty());

}




