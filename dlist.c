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
	/* Insert the new element */
}
