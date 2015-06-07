/* clist.h */

#ifndef CLIST_H_
#define CLIST_H_

#include <stlib.H>

/*Define a structure for circular list elements */
typedef struct CListElmt_{
	void *data
	struct ClistElmet_ *next;
}ClistElmt;

/* Define a structure for circuar lists*/
typedef struct Clist_{
	int size;
	int (*match) (const void *key1, const void *key2);
	void (*destory)(void *data);
	ClistElmt *head;
}CList;

/*Public Interface*/
void clist_init(Clist *list, void (*destory)(void *data));
void clist_destory(Clist *list);
int clist_ins_next(Clist *list, ClistElmt *element, const void *data);
int clist_rem_next(Clist *list, ClistElmt *element, void **data);
#define clist_size(list)((list)->size)
#define clist_head(list)((list)->head)
#define clist_data(element)((element)->data)
#define clist_next(element)((element)->next)

#endif
