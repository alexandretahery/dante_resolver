/*
** main.c for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 09:35:38 2017 Alexandre Tahery
** Last update Tue Apr 25 15:02:19 2017 Alexandre Tahery
*/

#include <stdlib.h>
#include "depth_dante.h"

int		depth_search(t_data_mazes *data_mazes,
			     int x,
			     int y,
			     t_array_node *top)
{
  int		found;

  found = FAIL;
  if (data_mazes->find_path == WAY_NO_FUND &&
      data_mazes->array_node[y][x].visited == NO_VISITED &&
      data_mazes->array_node[y][x].walk == TRUE)
    {
      data_mazes->array_node[y][x].father = top;
      data_mazes->array_node[y][x].visited = VISITED;
      depth_condition(data_mazes, x, y, found);
    }
  if (data_mazes->pos_end.x == x && data_mazes->pos_end.y == y)
    {
      data_mazes->find_path = WAY_FUND;
      return (SUCCESS);
    }
  return (found);
}

void		depth_condition(t_data_mazes *data_mazes,
				int x,
				int y,
				int found)
{
  if (x + 1 < data_mazes->x)
    found = depth_search(data_mazes, x + 1, y,
			 &data_mazes->array_node[y][x]);
  if (y + 1 < data_mazes->y && found == FAIL)
    found = depth_search(data_mazes, x, y + 1,
			 &data_mazes->array_node[y][x]);
  if (x - 1 >= 0 && found == FAIL)
    found = depth_search(data_mazes, x - 1, y,
			 &data_mazes->array_node[y][x]);
  if (y - 1 >= 0 && found == FAIL)
    found = depth_search(data_mazes, x, y - 1,
			 &data_mazes->array_node[y][x]);
}

void		put_into_char(t_data_mazes *data_mazes)
{
  t_array_node *tmp;

  tmp = &data_mazes->array_node[data_mazes->pos_end.y][data_mazes->pos_end.x];
  while (tmp != NULL)
    {
      data_mazes->array_char[tmp->pos.y][tmp->pos.x] = 'o';
      tmp = tmp->father;
    }
}

int		main(int argc, char **argv)
{
  t_data_mazes	data_mazes;

  if (argc == 1)
    return (FAIL);
  data_mazes.array_char = NULL;
  if ((data_mazes.array_char = field_char(argv[1])) == NULL
      || field_node(&data_mazes) == FAIL)
    return (FAIL);
  set_pos(&data_mazes);
  depth_search(&data_mazes, 0, 0, NULL);
  put_into_char(&data_mazes);
  display_tab(data_mazes.array_char);
}
