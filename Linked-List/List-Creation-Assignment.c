/*
 * List-Creation-assignment.c
 *
 *  Created on: Aug 23, 2017
 *      Author: RajeevSawant
 */

/*
 * Q: Write the code with the smallest number of assignments (=) which will build the
 * above memory structure. A: It requires 3 calls to malloc(). 3 int assignments (=) to setup
 * the ints. 4 pointer assignments to setup head and the 3 next fields. With a little cleverness
 * and knowledge of the C language, this can all be done with 9 assignment operations (=).
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

int main() {
	int count = 1;
	struct node *head = malloc (sizeof (struct node));      		//Create a head node
	struct node *conductor = head;									// Create a new node for traversing

	while (count < 20){
		conductor->data = 10 * count;

		if (count == 19){
			conductor->next = NULL;
		}else{
			conductor->next = malloc (sizeof (struct node));		// Creating any number of nodes
			conductor = conductor ->next;
		}

		++count;
	}

	conductor = head;
	while (conductor != NULL){
		printf("The value of the data is %d\n", conductor->data);
		conductor = conductor->next;
	}

	return 0;
}

