/* dlist.c */

#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/* dlist_init */
void dlist_init(Dlist *list, void (*destory)(void *data)){
	/* Initialize the list */
	list->size = 0;
	list->destory = destory;
	list->head = NULL;
	list->tail = NULL;
	return;
}

/* dlist_destory  */
void dlist_destory(Dlist *list){
	void *data;
	/* remove  each element*/
	while(dlist_size(list) > 0){
		if(dlist_remove(list,dlist_tail(list), (void **)&data) == 0 && list->destory != NULL){
			/*Call a user-defined function to free dynamixally allcoated data */
			list->dstory(data);
		}
	}
	/* No operations are allowed now , but clear the structure as a precaution */
	memset(list, 0, sizeof(Dlist));
	return;
}

/* dlist_ins_next */
int dlist_ins_next(Dlist *list, DlistElmet *element, const void *data){
	DlistElmet *new_element;
	/* Do not allow a NULL element unless the list is empty */
	if(element == NULL && dlist_size(list) != 0)
		return -1;
	/* Allcoate storage for the element */
	if((new_element = (DlistElmet *)malloc (sizeof(DlistElmet))) == NULL )
		return -1;
	/* Insert the new element into the list*/
	new_element->data = (void *)data;
	if(dlist_size(list) == 0){
		/* Handle insertion when the list is empty*/
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else{
		/* Handle inseration when the list is not empty*/
		new_element->next = element->next;
		new_element->prev = element;
		if(element->next == NULL)
			list->tail = new_element;
		else
			element->next->prev = new_element;
		element->next = new_element;
	}

	/* Adjust the size of the list to account for the inserted element */
	list->size++;
	return 0;
}

/* dlist_ins_prev */
int dlist_ins_prev(Dlist *list, DlistElmet *element, const void *data){
	DlistElmet *new_element;
	/* Do not allow a NULL element unless the list is empty */
	if(element == NULL && dlist_size(list) != 0)
		return -1;
	/* Allcoate storage for the element */
	if((new_element = (DlistElmet *)malloc (sizeof(DlistElmet))) == NULL )
		return -1;
	/* Insert the new element into the list*/
	new_element->data = (void *)data;
	if(dlist_size(list) == 0){
		/* Handle insertion when the list is empty*/
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else{
		/* Handle inseration when the list is not empty*/
		new_element->next = element;
		new_element->prev = element->prev;
		if(element->next == NULL)
			list->head = new_element;
		else
			element->prev = new_element;
		element->prev = new_element;
	}

	/* Adjust the size of the list to account for the inserted element */
	list->size++;
	return 0;
}

/* dlist_remove*/
int dlist_remove(Dlist *list, DlistElmet *element, void **data){
	/* Do not allow a NULL element or removal from an empty list*/
	if(element == NULL || dlist_size(list) == 0)
		return -1;
	/* remove the elemnet from the list*/
	*data = element->data;
	if(element == list->data){
		/*Handle removal from thee head of the list*/
		list->head = element->next;
		if(list->head == NULL)
			list->tail =NULL;
		else
			element->next->prev = NULL;
	}
	else{
		/* Handle removal from other than the head of the list*/
		element->prev->next == element->next;
		if(element->next == NULL)
			list->tail = element->prev;
		else
			element->next->prev = element->prev;

	}
	/*Free the storage allcoated by the abstract datatype*/

	free(element);

	list->size--;
	return 0;

}
