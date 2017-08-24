/*
 * Create-List.c
 *
 *  Created on: Aug 23, 2017
 *      Author: RajeevSawant
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
	int data;
	int key;
	struct node *next;
};

int main(){
	struct node *head = NULL;
    struct node *second = NULL;
    struct node *third  =  NULL;

    /* If we just write node instead of struct node, we get and error
     *  "use of undeclared identifier 'node' "
     *
     */
    head    = malloc (sizeof (struct node));       // Allocate 3 nodes in heap
    second  = malloc (sizeof (struct node));
    third   = malloc (sizeof (struct node));

    head -> data = 1;
    head -> key  = 10;
    head -> next = second;

    second -> data = 2;
    second -> key  = 20;
    second -> next = third;

    third -> data = 3;
    third -> key  = 30;
    third -> next = NULL;

    struct node *container =  head;
    while (container != NULL){
    	printf(" Data = %d , Key = %d \n", container->data, container->key );
    	container = container->next;
    }

    return 0;
}




