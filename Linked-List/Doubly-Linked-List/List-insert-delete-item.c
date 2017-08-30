/*
 * Double-LinkList.c
 *
 *  Created on: Aug 30, 2017
 *      Author: RajeevSawant
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	struct node * prev;
	int data;
	struct node * next;
};

struct node * head = NULL;
struct node * last = NULL;


bool isEmpty(){
	if (head == NULL){
		return true;
	}else{
		return false;
	}
}


int length(){
	struct node * container = head;
	int count = 0;

	while (container != NULL){
		count++;
		container = container->next;
	}
	return count;
}

void insert_item_first(int data){
	struct node * container = malloc (sizeof (struct node));

	if (isEmpty()){
		last = container;
	}else{
		head->prev = container;
	}

	container->data = data;
	container->next = head;
	container->prev = NULL;
	head = container;
}



void insert_item_last(int data){
	struct node * container = malloc (sizeof (struct node));

	if (isEmpty()){
		last = container;

	}else{
		last->next = container;
	}

	container->data = data;
	container->prev = last;
	container->next = NULL;
	last = container;

}

void print_item_forward(){
	struct node *container = head;

	while (container != NULL){
		printf(" The data is  %d\n", container->data);
		container = container->next;
	}
}

void print_item_backward(){
	struct node *container = last;

	while (container != NULL){
		printf(" The data is %d\n", container->data);
		container = container->prev;
	}
}

void delete_item_first(){
	struct node * container = head;

	if (!isEmpty()){
		container = container->next;
		head->next = container->next;
		container->next->prev = head;
	}
	head = container;

}

void delete_item_last(){
	struct node * container = last;

	if (!isEmpty()){
		container = container->prev;
		container->next = NULL;
	}
	last = container;
}



void delete_item(int data){
	struct node * container = head;
	struct node * next_item = container->next;

	if (container != NULL & container->data != data){
		while (container->next->data != data){
			container = container->next;
			next_item = next_item->next;
		}
		container->next = next_item->next;
		next_item->next->prev = container;
	}else{
		head = container->next;
	}

}




int main(){
	insert_item_first(10);
	insert_item_first(20);
	insert_item_first(40);
	insert_item_first(30);
	insert_item_first(80);
	insert_item_first(50);
	insert_item_first(90);


	printf("\n Printing the Inserted data \n");
	print_item_forward();

	insert_item_last(84);
	insert_item_last(53);
	insert_item_last(98);

	printf("\n Printing the Data inserted from last\n");
	print_item_forward();

	printf("\n Printing the Data in backward \n");
	print_item_backward();

	printf("\n Printing the updated List after Deleting the First Item \n");
	delete_item_first();
	print_item_forward();

	printf("\n Printing the updated List after Deleting the Last Item \n");
	delete_item_last();
	print_item_forward();

	printf("\n Printing the updated List after Deleting a particular Item \n");
	delete_item(30);
	print_item_forward();




	return 0;
}


