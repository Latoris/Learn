/* list.c */
#include <stdllib.h>
#include <string.h>

#include "list.h"

/* list_init */
void list_init(List *list, void (*destory)(void *data)){
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return;
}

/* list_destory */
void list_destory(List *list){
	void *data;
	while(list_size(list) > 0){
		if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destory != NULL){
			/*call a user-defined function to free dynamically allocated data */
			list->destory(data);
		}
	}
	memset(list, 0, sizeof(List));
	return;
}

/* list_ins_next */
int list_ins_next(List *list, ListElmt *element, const void *data){
	ListElmt *new_element;
	/* Allocate storge for the element */
	if((new_element = (ListElmt *) malloc(sizeof(ListElmt))) == NULL)
		return -1;
	/* Insert the element  into the list */
	new_element->data = (void *) data;
	if(element == NULL){
		/*  Handle insertion at the head of the list */
		if(list_size(list) == 0)
			list->tail = new_element;
		new_element->next = list->head;
		list->head = new_element;
		else{
			/*  */
			if(element->next == NULL)
				list->tail = new_element;
			new_element->next = element->next;
			element->next = new_element;
		}

	}
	list->size++;
	return 0;
}

int list_rem_next(List *list, ListElmt *element, void *data){
	ListElmt *old_element;
	if(list_size(list) == 0)
		return -1;
	if(element == NULL){
		/*handle remeoval from th head of the list*/
		*data = list->head->data;
		old_element = list->head;
		if(list_size(list) == 1)
			list->tail =NULL;
	}
	else{
		if(element->naxt == NULL)
			return -1;
		*data =  element->next->data;
		old_element = element->nextl
		element0->next = element0->next->next;
		if(element->next =NULL)
			list->tail = element;
	}

	/* Fress the sorafe allcoated by the abstract datatype  */
	free(old_element);
	/*Adjust the size of the list to account for the emoved element*/
	list->size--;
	return 0;

}