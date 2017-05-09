/*
** init_fonc.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar/src_path
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:56:05 2017 Alexandre Tahery
** Last update Fri Apr 28 12:59:11 2017 Alexandre Tahery
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "astar.h"

char		**build_field_char(char *str, char **array, int count)
{
  char		**tmp;
  int		count_l;

  count_l = 0;
  if ((tmp = malloc(sizeof(char *) * (count + 2))) == NULL)
    return (NULL);
  while(count_l != count)
    {
      tmp[count_l] = array[count_l];
      count_l += 1;
    }
  tmp[count_l] = str;
  tmp[count_l + 1] = NULL;
  return (tmp);
}

char		**field_char(char *argv)
{
  char		*str;
  char		**array_char;
  int		count;
  int		old_len;
  int		len;
  int		fd;

  len = 0;
  old_len = 0;
  if ((fd = open(argv, O_RDONLY)) < 0)
    return (NULL);
  count = 0;
  array_char = NULL;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (count == 0)
	old_len = my_strlen(str);
      if ((len = my_strlen(str)) != old_len)
	return (NULL);
      array_char = build_field_char(str, array_char, count);
      old_len = my_strlen(str);
      count += 1;
    }
  close(fd);
  return (array_char);
}

void		set_pos(t_data_map *data_map)
{
  data_map->pos_begin[X_POS] = 0;
  data_map->pos_begin[Y_POS] = 0;
  data_map->pos_end[X_POS] = my_strlen(data_map->array_char[0]) - 1;
  data_map->pos_end[Y_POS] = my_strlen_tab((int **)data_map->array_char) - 1;
}
