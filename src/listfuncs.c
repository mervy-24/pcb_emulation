//
//Author: mervy24
//

#include "listfuncs.h"

int 
insert(struct List_item *listHead, struct List_item *insertItem)
{
	// Invalid arguments
	if (listHead == NULL || insertItem == NULL || insertItem->node == NULL || insertItem->node->pid < 0)
		return 0;

	List_item *current = listHead; // Set the current pointer to head item to start with.
	// Check for duplicates
    	while (current != NULL)
	{
        	if (current->node->pid == insertItem->node->pid)
			// Duplicate PID found, do not insert
			return 0;
        	current = current->next;
    	}
	// Insert item at the head if the list is empty
    	if (listHead->node == NULL)
	{
        	listHead->node = insertItem->node;
        	listHead->next = NULL;
        	return 1;
    	}
	// For when current pid < than insertItem pid (till end of the list): 
	current = listHead;
	List_item *prev = NULL;
	while (current != NULL && current->node->pid < insertItem->node->pid)
	{
		// Looping through list:
		prev = current;
		current = current->next;
	}
	// For at the start of the list and the current !> than the insertItem:
	if (prev == NULL)
	{
		// Inserts item before 'original' list head:
		insertItem->next = listHead; 
	} else
	{
		prev->next = insertItem;
		insertItem->next = current;
	}
	return 1;
}

int
delete(struct List_item *listHead, int pid)
{
	if (listHead == NULL || pid <= 0)
		return 0;
	List_item *current = listHead;
	List_item *prev = NULL;
	// Loop through list while current pid isn't pid to be deleted (till end of the list):
	while (current != NULL && current->node->pid != pid)
	{
		// Looping through list:
		prev = current;
		current = current->next;
	}
	// If pid to delete is not found:
	if (current == NULL)
		return 0;
	// Deletes head (not while loop ensures that if the head pid doesn't match the specified pid to be deleted, the list will be looped through):
	if (prev == NULL)
	{
		listHead = current->next;
	} else
	{
		prev->next = current->next;
	}
	// Deallocating memory:
	free(current->node);
	free(current);
	return 1;
}

void
printList(struct List_item *listHead)
{
	List_item *current = listHead;
	// Loop through list and print pid and name:
	while (current != NULL)
	{
		printf("%d\t%s\n", current->node->pid, current->node->name);
		current = current->next;
	}
}
