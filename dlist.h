/* dlist.h */
//双向链表的实现

#ifndef DLIST_H_
#define DLIST_H_

#include <stlib.h>

/* Define a structure for doubly-linked list elements */
typedef struct DListElmt_{
	void *data;
	struct DListElmt_ *prev;
	struct DListElmt_ *next;
}DListElmt;

/* Define a structure for doubly-linked lists */
typedef struct Dlist_{
	int size;
	int (*match)(const void *key1, const *key2);
	void (*destory)(void *data);
	DlistElmt *head;
	DlistElmt *tail;
}Dlist;

/* Public Inteface */
void dlist_init(Dlist *list, void(*destory)(void *data));
void dlist_destory(Dlist *list);
int dlist_ins_prev(Dlist *list, DlistElmt *element, const void *data);
int dlist_ins_next(Dlist *list, DlistElmt *element, const void *data);
int dlist_remove(Dlist *list, DlistElmt *element, void **data);
#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULL ? 1:0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1:0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif