/*
 * List-sort-items.c
 *
 *  Created on: Aug 26, 2017
 *      Author: RajeevSawant
 */

#include <stdio.h>      // For IO operations
#include <stdlib.h>     // For malloc



struct node {
	int data;
	struct node * next;
};

struct node * head = NULL;

void  add_item(int data){
	struct node* container = malloc(sizeof(struct node));

	container->data = data;
	container->next = head;

	head = container;
}

void print_item(){
	struct node * container = malloc(sizeof (struct node));

	container = head;
	while(container != NULL){
		printf("\n The data value is %d",container->data);
		container = container->next;
	}

}


void delete_item(int data){
	struct node * container = malloc (sizeof (struct node));

	container = head;
	if(container != NULL & container->data != data){
		while (container->next->data != data){
			container = container->next;
		}
		container->next = container->next->next;
	}else{
		head = container->next;
	}
}


const char* isEmpty(){
	if (head == NULL){
		return "True";
	}else{
		return "False";
	}
}

struct node * find_item(int data){
	struct node * container = malloc (sizeof (struct node));

	container = head;
	if (container == NULL){
		return NULL;
	}

	while  (container != NULL ){
		if (container->data != data){
			container = container->next;
		}else{
			return container;
		}

	}
	return NULL;
}


void reverse_item(){

	struct node * prev = NULL;
	struct node * current = head;
	struct node *  next = NULL;

	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

void ascending_sort(){
	struct node* current = head;
	int temp, count = 0, k;

	while (current != NULL){
		current = current->next;
		count++;
	}
	k = count;
	printf("\n The value of count is %d\n", count);

	for (int i= 0; i < count - 1; i++, k--){
		current = head;

		for (int j = 1; j < k ; j++){

			if (current->data > current->next->data ){
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;

			}
			current = current->next;

		}

	}

}

int main(){
	add_item(50);
	add_item(4);
	add_item(36);
	add_item(20);
	add_item(13);
	add_item(12);
	add_item(10);
	add_item(11);
	add_item(19);
	add_item(1);

	printf("\n List Items are ");
	print_item();

	printf("\n\n List after Deleting the item is ");
	delete_item(10);
	print_item();

	printf("\n\n Is the List Empty %s ", isEmpty());

	struct node * finder = find_item(300);
	if (finder != NULL){
		printf("\n Item Searching is %d",finder->data);
	}else{
		printf("\n Item Not Found\n");
	}

	if (head != NULL){
		printf("\n Reverse of the List Items ");
		reverse_item();
		print_item();
	}else{
		printf("\n There are no Items in the List \n");
	}

	printf("\n\n Sorted list in ascending Order");
	ascending_sort();
	print_item();

	return 0;
}


