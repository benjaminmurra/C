#include <stdbool.h>
#ifndef  __FUNCTION_HEADER
#define  __FUNCTION_HEADER  

typedef struct _AList {
	void **arr;
	int size;
	int maxSize;
	int itemSize;
	char* type;
} ArrayList;


ArrayList* alist_initialize(int , int , char* );
bool alist_add(ArrayList* , void* );
bool alist_add_at(ArrayList* , int , void* );
void alist_clear(ArrayList* );
void* alist_get(ArrayList* , int );
int alist_index_of(ArrayList* , void* );
void* alist_remove(ArrayList* , int ) ;
bool alist_destroy(ArrayList* );
bool alist_resize(ArrayList* );


#endif