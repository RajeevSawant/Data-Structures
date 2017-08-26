/*
 * List-Find_Item-and-Reverse_Item.c
 *
 *  Created on: Aug 24, 2017
 *      Author: RajeevSawant
 */



#include <stdlib.h>      // For malloc
#include <stdio.h>       // For IO operations
#include <stdbool.h>     // For bool
#include <strings.h>


struct node{
	int data;
	struct node *next;
};


struct node* head = NULL;

void add_item (int data){
	struct node* container = malloc (sizeof (struct node));

	container->data = data;
	container->next = head;

	head = container;
}

void print_item(){
	struct node* temp = NULL;

	temp = head;
	while (temp != NULL){
		printf("The data in the node is %d\n", temp->data);
		temp = temp->next;
	}
}


void delete_item(int data){
	struct node* container = malloc (sizeof (struct node));

	container = head;
	if (container != NULL & container->data != data){
		while (container->next->data != data){
			container = container->next;
		}
		container->next = container->next->next;
	}else{
		head = container->next;
	}

}


struct node* find_item(int data){
	struct node* container = malloc (sizeof (struct node));

	container = head;
	if (container != NULL || container->next != NULL){
		while (container->data != data){
			container = container->next;
		}
		return container;
	}else{
		return NULL;
	}

}


void reverse_item(){
 struct node * current = head;
 struct node * next = malloc (sizeof (struct node));
 struct node * prev = NULL;

 while (current != NULL){
	 next = current->next;
	 current->next = prev;
	 prev = current;
	 current = next;
 }
 head = prev;
}


const char *  isEmpty(){
	struct node * container = malloc (sizeof (struct node));
	container = head;
	if (head != NULL){
		return "false";
	}else{
		return "true";
	}
}


int main(){

	add_item(10);
	add_item(20);
	add_item(50);
	add_item(30);
	add_item(40);


	printf("The List is \n");
	print_item();


	printf("\nDelete one item \n");
	delete_item(40);
	print_item();

	struct node *finder = find_item(50);
	if (finder != NULL){
		printf ("\nThe data of the found item is %d\n", finder->data);
	}else{
		printf("\nElement not found\n");
	}


	printf ("\nIs the List Empty %s \n",isEmpty());


	printf("\n Reverse of the string is \n");
	reverse_item();
	print_item();



	return 0;
}

