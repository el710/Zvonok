#include "EventList.h"

#include "malloc.h"

#define STAT_MEM

#ifdef STAT_MEM
T_Item  Stat_mem_item[100];

unsigned int new_iter;
#endif;


void EList_init(T_EList* list)
{
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
#ifdef STAT_MEM
   new_iter = 0;
#endif
}

void EList_free(T_EList* id_list)
{
#ifdef STAT_MEM
   id_list->first = NULL;
   id_list->last = NULL;
   id_list->size = 0;
   new_iter = 0;
#else
 void* a;
 T_Item* b = id_list->last;


 for(int i = 0; i<id_list->size; i++)
 {
   a = b->prev;
   free(b);
   if(a != NULL) b = (T_Item*)a;
 }

 free(id_list);
#endif
}


T_Item* EList_push(T_EList* id_list, t_Event* in_event)
{
  T_Item* new_item;
  char* p_char;

#ifndef STAT_MEM
   new_item = (T_Item*) malloc(sizeof(T_Item));
   if( new_item == NULL ) return NULL;
#else
   if(new_iter<100)
   {
     new_item =  &Stat_mem_item[new_iter];
     new_iter++;
   }
   else  return NULL;
#endif

  new_item->next = NULL;
  new_item->event.start_date = in_event->start_date;
  new_item->event.start_time = in_event->start_time;
  new_item->event.cycle_flags.all_flags = in_event->cycle_flags.all_flags;
  new_item->event.event_sign.all_signs = in_event->event_sign.all_signs;

  p_char = (char *) malloc(MESSAGE_ROW_SIZE);
  if( p_char == NULL )
  {
   #ifdef STAT_MEM
      new_item = NULL;
   #else
      free(new_item);
   #endif
   return NULL;
  }
  new_item->event.caption = p_char;
  strcpy(new_item->event.caption, in_event->caption);

  p_char = (char *) malloc(SOUND_FILENAME_SIZE);
  if( p_char == NULL )
  {
   free(new_item->event.caption);
   #ifdef STAT_MEM
      new_item = NULL;
   #else
      free(new_item);
   #endif
   return NULL;
  }
  new_item->event.sound = p_char;
  strcpy(new_item->event.sound, in_event->sound);

  if(id_list->size ==0)
  {
    new_item->prev = NULL;
    id_list->first = new_item;
  }
  else
  {
    new_item->prev = id_list->last;
    id_list->last->next = new_item;
  }

  id_list->last = new_item;
  id_list->size++;

  return new_item;
}


t_Event EList_get(T_EList* id_list, unsigned int in_num)
{
 T_Item* iter = id_list->first;


 if((in_num + 1) > id_list->size) return id_list->last->event;

 for( unsigned int i = 0; i < in_num; i++ )
 {
   iter = (T_Item*)iter->next;
 }


 return iter->event;
}






