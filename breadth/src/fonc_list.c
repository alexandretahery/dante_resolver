/*
** fonc_list.c for dante in /home/alexandre/rendu/2016/CPE/dante/breadth/srcv2
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 11:12:05 2017 Alexandre Tahery
** Last update Fri Apr 28 11:19:47 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "breadth_dante.h"

t_array_node	*put_end_of_list(t_array_node *list,
				 t_array_node *elem,
				 t_array_node *top)
{
  t_array_node	*tmp;

  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (elem->visited == NO_VISITED)
    {
      elem->visited = VISITED;
      tmp->next = elem;
      elem->father = top;
      elem->next = NULL;
    }
  return (list);
}

t_array_node	*delete_begin_of_list(t_array_node *list)
{
  t_array_node	*tmp;

  if (list == NULL)
    return (NULL);
  tmp = list->next;
  list = tmp;
  return (list);
}
