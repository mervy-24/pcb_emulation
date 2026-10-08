//
//Author: mervy24
//

#include "listfuncs.h"

int
main()
{
	// Allocating memory to PCB's:
	PCB *pcb1 = (PCB *)malloc(sizeof(PCB));
	PCB *pcb2 = (PCB *)malloc(sizeof(PCB));
	PCB *pcb3 = (PCB *)malloc(sizeof(PCB));
	PCB *pcb4 = (PCB *)malloc(sizeof(PCB));

	// Setting pid's to the pcb's:
	pcb1->pid = 1;
	pcb2->pid = 15;
	pcb3->pid = 7;
	pcb4->pid = 7;

	// Setting proc names to the pcb's:
	strcpy(pcb1->name, "proc1");
	strcpy(pcb2->name, "proc15");
	strcpy(pcb3->name, "proc7");
	strcpy(pcb4->name, "proc0");

	// Allocating memory for list items and setting them up with nodes as pcb's:
	List_item *head = (List_item *)malloc(sizeof(List_item));
    	head->node = NULL;
    	head->next = NULL;

    	List_item *item1 = (List_item *)malloc(sizeof(List_item));
    	head->node = pcb1;
    	head->next = NULL;
	
    	List_item *item2 = (List_item *)malloc(sizeof(List_item));
	item2->node = pcb2;
    	item2->next = NULL;
	
    	List_item *item3 = (List_item *)malloc(sizeof(List_item));
    	item3->node = pcb3;
    	item3->next = NULL;

    	List_item *item4 = (List_item *)malloc(sizeof(List_item));
    	item4->node = pcb4;
    	item4->next = NULL;

	// Where the magic happens
	// Test function 1 (and 3), insertion and printing:
	printf("1st insert:\n");
	insert(head, item1);
	printList(head);

	printf("\n2nd insert:\n");
	insert(head, item2);
	printList(head);

	printf("\n3rd insert:\n");
	insert(head, item3);
	printList(head);

	printf("\n4th insert: (Unsuccessful)\n");
	insert(head, item4);
	printList(head);

	// Test function 2, deletion:
	printf("\n1st deletion:\n");
	delete(head, 7);
	printList(head);
	
	printf("\n2nd deletion: (Unsuccessful)\n");
	delete(head, 3);
	printList(head);

	printf("\n3rd deletion:\n");
	delete(head, 15);
	printList(head);
	
	// Freeing allocated memory to ensure no memory leak:
  List_item *current = head;
  while (current != NULL)
	{
    List_item *next = current->next;
    free(current->node);
    free(current);
    current = next;
  }
}
