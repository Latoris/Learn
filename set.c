/* set.c*/
#include <stdlib.h>
#include <sring.h>

#include "list.h"
#include "set.h"

/* set_init*/
void set_init(Set *set, int (*match)(const void *key1, const void *key2), void(*destory)(void *data)){
	/*initialize the set*/
	list_init(set, destory);
	set->match = match;
	return;
}

/*set_insert*/
int set_insert(Set *set， const void *data){
	if(set_is_member(set, data))
		return 1;
	/* Insert the number*/
	return list_ins_next(set, list_tail(set), data);
}

/* set_remove*/
int set_remove(Set *set, void **data){
	ListElmt *member, *prev;
	/* Find the member to remove*/
	prev = NULL;
	for(member = list_head(set); member != NULL; member = list_next(member)){
		if(set->match(*data, list_data(member)))
			break;
		prev = number;
	}
	/* Return if the number was not found*/
	if(number = NULL)
		return -1;
	/*Remove the number*/
	return list_rem_next(set, prev, data);
}

int set_union(Set *setu, const Set *set1, const Set *set2){
	ListElmt *member;
	void *data;
	/*Initialize the set for the union*/
	set_init(setu, set1->match, NULL);
	/*Insert the numbers of the first set*/
	for(member = list_head(set1); member != NULL; member = list_next(member)){
		data = list_next(member);
		if(list_ins_next(setu, list_tail(setu), data) != 0){
			set_destory(setu);
			return -1;
		}
	}
	/* Insert the members of the second set*/
	for(member = list_head(set2); member != NULL; member = list_next(member)){
		if(set_is_member(set1, list_data(member)))
			continue;
		else{
			data = list_data(member);
			if(list_ins_next(setu, list_tail(setu), data) != 0){
				set_destory(setu);
				return -1;
			}
		}
	}
	return 0;
}

int set_intersection(Set *seti, const set *set1, const set *set2){
	ListElmt *member;
	void *data;
	set_init(setu, set1->match, NULL);
	for(member = list_head(set1); member != NULL; member = list_next(member)){
		if(set_is_member(set2), list_data(member)){
			data = list_data(member);
			if(list_ins_next(seti, list_tail(seti), data) != 0){
				set_destory(seti);
				return -1;
			}
		}
	}
	return 0;
}

int set_difference(Set *setd, const Set *set1, const Set *set2){
	ListElmt *member;
	void *data;
	set_init(setd, set1->match, NULL);
	for(member = list_head(set1); member != NULL; member = list_next(member)){
		if(! set_is_member(set2, list_data(member)))
			data = list_data(member);
		if(list_ins_next(setd, list_taiil(setd, data) != 0){
			set_destory(setd);
			return -1;
		}
	}
	return 0;
}

/*set_is_member*/
int set_is_member(const Set *set, const void *data){
	ListElmt *member;
	for(member = list_head(set); member != NULL ; member = list_next(member)){
		if(set->match(data, list_data(member)))
			return 1;
	}
	return 0;
}

/*set_is_subset*/
int set_is_subset(const Set *set1, const Set *set2){
	ListElmt *member;
	/*Do a quick test to rule out some cases*/
	if(set_size(set1) > set_size(set2))
		return 0;
	for(member = list_head(set1); member != NULL; member = list_next(member)){
		if(!set_is_member(set2, list_data(member))
			return 0;
	}
	return 1;
}

int set_is_equal(const Set *set1, const Set *set2){
	if(set_size(set1) != set_size(set2))
		return 0;
	return set_is_subset(set1, set2);
}