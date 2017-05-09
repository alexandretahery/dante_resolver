/*
** a_star.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_path
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:55:47 2017 Alexandre Tahery
** Last update Fri Apr 28 12:55:48 2017 Alexandre Tahery
*/

#include <math.h>
#include <stdlib.h>
#include "astar.h"

t_array_node	*end_of_list(t_array_node *list, t_array_node *node)
{
  t_array_node *tmp;

  if (list == NULL)
    return (node);
  tmp = list;
  while (tmp->list_p != NULL)
    tmp = tmp->list_p;
  tmp->list_p = node;
  return (list);
}

void		heuristic_fonc(t_data_map *data_map,
			       t_2int *around,
			       t_2int *pos,
			       int weight)
{
  int		x_father;
  int		y_father;
  int		x_child;
  int		y_child;

  x_father = pos->x;
  y_father = pos->y;
  x_child = pos->x + around->x;
  y_child = pos->y + around->y;
  data_map->array_node[y_child][x_child].father =
    &data_map->array_node[y_father][x_father];
  data_map->array_node[y_child][x_child].h =
    ((abs(data_map->pos_end[X_POS] - x_child)
      + abs(data_map->pos_end[Y_POS] - y_child)) * 10);
  data_map->array_node[y_child][x_child].g = weight +
    data_map->array_node[y_child][x_child].father->g;
  data_map->array_node[y_child][x_child].f =
    data_map->array_node[y_child][x_child].g +
    data_map->array_node[y_child][x_child].h;
  data_map->array_node[y_child][x_child].list = OPEN_LIST;
  if (data_map->array_node[y_child][x_child].list_p == NULL)
    data_map->open_list = end_of_list(data_map->open_list,
				      &data_map->array_node[y_child][x_child]);
}


void			case_node_none_list(t_data_map *data_map,
					    t_2int *count_pos,
					    t_2int *around)
{
  int			pos_child[2];

  if ((count_pos->x + around->x) >= 0
      && (count_pos->y + around->y) >= 0
      && (count_pos->x + around->x) < data_map->x
      && (count_pos->y + around->y) < data_map->y)
    {
      pos_child[X_POS] = count_pos->x + around->x;
      pos_child[Y_POS] = count_pos->y + around->y;
      if ((around->x != 0 || around->y != 0)
	  && data_map->array_node[pos_child[Y_POS]][pos_child[X_POS]].walk == TRUE
	  && data_map->array_node[pos_child[Y_POS]][pos_child[X_POS]].list == NONE_LIST)
	{
	  if (around->x == 0 || around->y == 0)
	    heuristic_fonc(data_map, around, count_pos, 10);
	}
    }
}

int			choose_next_node(t_data_map *data_map)
{
  t_array_node		*tmp;
  int			f_little;

  if ((f_little = find_little_f(data_map)) == -1)
    {
      return (FAIL);
    }
  tmp = data_map->open_list;
  while (tmp != NULL)
	{
	  if (tmp->list == OPEN_LIST && tmp->f == f_little)
	    {
	      data_map->pos_begin[X_POS] = tmp->pos.x;
	      data_map->pos_begin[Y_POS] = tmp->pos.y;
	      tmp->list = CLOSE_LIST;
	      return (SUCCESS);
	    }
	  tmp = tmp->list_p;
	}
  return (FAIL);
}

void			a_star(t_data_map *data_map)
{
  t_2int		count_pos;
  t_2int		around;

  while (data_map->pos_begin[X_POS] != data_map->pos_end[X_POS]
	 || data_map->pos_begin[Y_POS] != data_map->pos_end[Y_POS])
    {
      count_pos.x = data_map->pos_begin[X_POS];
      count_pos.y = data_map->pos_begin[Y_POS];
      around.y = -1;
      while (around.y <= 1)
	{
	  around.x = -1;
	  while (around.x <= 1)
	    {
	      case_node_none_list(data_map, &count_pos, &around);
	      around.x += 1;
	    }
	  around.y += 1;
	}
      if(choose_next_node(data_map) == FAIL)
	return ;
    }
  data_map->way =
    &data_map->array_node[data_map->pos_end[Y_POS]]
    [data_map->pos_end[X_POS]];
}
