//
// Author: mervy24
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PCB Structure
typedef struct PCB {
	int pid;
	char name[16];
} PCB;

// List item Structure
typedef struct List_item {
	PCB *node;
	struct List_item *next;
} List_item;

// Function prototypes:
int insert(struct List_item *listHead, struct List_item *insertItem); // 1
int delete(struct List_item *listHead, int pid); // 2
void printList(struct List_item *listHead); // 3

