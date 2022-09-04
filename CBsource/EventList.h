#ifndef EVENTLIST_H
#define EVENTLIST_H


#include "Schedlib.h"


typedef struct
{
  t_Event event;

  void* prev;
  void* next;
} T_Item;


typedef struct
{
  T_Item* first;
  T_Item* last;

  unsigned int size;
} T_EList;


T_EList* EList_new();
void EList_init(T_EList* list);

void EList_free(T_EList* id_list);

T_Item* EList_push(T_EList* id_list, t_Event* in_event);

t_Event EList_get(T_EList* id_list, unsigned int in_num);



#endif //EVENTLIST_H
 