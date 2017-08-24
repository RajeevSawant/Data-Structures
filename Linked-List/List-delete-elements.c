#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

void add_item(int data){
	struct node* container =  malloc(sizeof(struct node));     	//	 Create a new node
	container->data = data;  									//	 assign it to data
	container->next = head;										//	 Point the newly created head to next

	head = container;											//	 Make the current newly created node as the head node
}

void print_item(){
	struct node* new_node = malloc (sizeof (struct node));

	new_node = head;
	while (new_node != NULL){
		printf("The value of the newly created node is %d\n", new_node->data);
		new_node = new_node->next;
	}
}

void delete_item (int data){
	struct node* current_node = malloc (sizeof (struct node));
	//	struct node* prev_node = malloc (sizeof (struct node));
	current_node = head;
	while (current_node->next->data != data){             // Check if the data of next node matches data to be removed
		current_node = current_node->next;
	}
	current_node->next = current_node->next->next;        // Assign the next to next node to current node.

}


int main(){
	add_item(50);
	add_item(40);
	add_item(30);
	add_item(20);
	add_item(10);

	print_item();

	delete_item(30);
	printf("\nThe Updated List \n");
	print_item();

	return 0;
}

