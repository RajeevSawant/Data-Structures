#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	struct node * next;
};

struct node * head = NULL;

void add_item (int data){
	struct node *container = new node;

	container->data = data;
	container->next = head;

	head = container;
}


void remove_duplicate(){
	struct node * after = new node;
	struct node * current = new node;
	struct node * previous = new node;
//	int temp;

	after = head;

	while (after!= NULL){
		current = after;
		while (current->next != NULL){
			if (after->data == current->next->data){
                // previous = current->next;
                 current->next = current->next->next;
                // delete(previous);
			}else{
				current = current->next;
			}
		}
		after = after->next;

	}

}


void print_item (){
	struct node *container = new node;

	container = head;
	while(container != NULL){
		cout << " The data in the list is " << container->data << endl;
		container = container->next;
	}
}


void delete_first_item(){
	struct node *container = new node;

	container = head;
	if (container != NULL){
		container = container->next;
		head = container;
	}

}


void insert_item(int data, int after_data){
	struct node* container = new node;
	struct node* new_element  = new node;
	int flag = 0;
	new_element->data = data;

	container = head;

	while ((container!= NULL)){
		if (container->data == after_data){
			flag = 1;
			new_element->next = container->next;
			container->next = new_element;
			break;
		}else{
			container = container->next;
		}
	}

	if (flag == 0){
		printf("\n DATA NOT FOUND\n\n");
	}


}




void delete_item(int data){
	struct node *container = new node;

	container = head;
	while (container != NULL){
		if (container->next->data != data){
//			cout << "line 117"<< endl;
			container = container->next;
		}else{
			container->next = container->next->next;
			break;
//			cout << "Data is  " << container->next->data <<endl;
		}
	}
}


void reverse_item(){
	struct node * current = new node;
	struct node * previous = new node;
	struct node * after = new node;

	current = head;
	while (current != NULL){
		after = current->next;
		current->next = previous;
		previous = current;
		current = after;
	}

	head = previous;
}



void sort(){
	struct node *current = new node;
	int temp, k = 0, length = 0;

	current = head;
	while (current != NULL){
		current = current->next;
		length++;
	}
	k = length;

	for (int i = 0; i < k -1; i++, k--){
		current = head;
		for (int j = 1; j < k; j++){
			if (current->data > current->next->data){
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
	}
}


struct node* The_nth_node(int node_number){

	struct node * container = new node;
	int length = 0, count = 0;
	container = head;

	while (container != NULL){
		container = container->next;
		length++;
	}

	container = head;
	while (container!= NULL){
		if (count == (length - node_number)){
			return container;
			break;
		}else{
			container= container->next;
			count++;
		}
	}
	return NULL;
}



int main() {

	// Add the item in the list
	add_item(20);
	add_item(10);
	add_item(40);
	add_item(60);
	add_item(30);
	add_item(30);
	add_item(10);
	add_item(40);



	// Print the added items
	print_item();

	// delete the first item
	delete_first_item();

	printf("\n The deleted item in the list \n\n");
	//Print the list after deleting the first item
	print_item();


	printf("\n List after inserting an Item \n\n");
	insert_item(35,40);
	print_item();

	printf("\n Delete the item from the list \n\n");
	delete_item(60);
	print_item();

	//    printf(" \n Reverse the List \n\n");
	//    reverse_item();
	//    print_item();
	printf("  \n Remove Duplicate \n\n");
	remove_duplicate();
	print_item();


	printf(" \n Sorted List is \n\n");
	sort();
	print_item();


	printf(" \n The value of the nth node is ");
	struct node *contain_chamber = The_nth_node(3);
	cout<< " "<<contain_chamber->data << endl <<endl;


	return 0;
}

