/*  list.h  */
/*  单链表的实现   */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

/* Define a structure for linked list element elements */

typedef struct ListElmt_{
	void *data;
	struct ListElmt_ *next;
}ListElmt_;

/* define a structue for linked lists */
typedef struct  struct_List_{
	int size;//链表中元素的个数
	int (*match)(const void *key1, const void *key2);
	void (*destory) (void *data);//封装之后传递给list_init的析构函数
	ListElmt_ *head;//指向链表中头结点元素的指针
	ListElmt_ *tail;//指向链表中尾结点元素的指针
}List;

/* Public Intrerface */
void list_init(*list, void(*destory)(void * data));
void list_dedtory(List *list);
int list_ins_next(List *list, ListElmt_ *element ,const void *data);
int list_rem_next(List *list, ListElmt_ *element, void **data);

#define list_size(list) ((list)->size)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element)((element) == (list)->head ? 1 ： 0)
#define list_is_tail(element)((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif