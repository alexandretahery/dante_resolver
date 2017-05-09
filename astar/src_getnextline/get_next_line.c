/*
** get_next_line.c for dante in /home/alexandre/rendu/2016/CPE/dante/astar
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:54:49 2017 Alexandre Tahery
** Last update Fri Apr 28 12:54:49 2017 Alexandre Tahery
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		my_strlen_g(char *str, char c, int s)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != c && str[i] != '\0')
    i++;
  if (str[i] == c)
    return (i);
  if (str[i] == '\0' && s == 1)
    return (0);
  return (i);
}

static char	*my_strncpy(char *dest, char *src, int n)
{
  int		c;

  c = 0;
  while (src[c] != '\0' && n != c)
    {
      dest[c] = src[c];
      c = c + 1;
    }
  if (n < c)
    {
      dest[c] = '\0';
    }
  return (dest);
}

char		*copy_str(t_data *data, t_stat *stat)
{
  char		*str;
  int		len;

  if (data->str == 0)
    len = 0;
  else
    len = my_strlen_g(data->str, '\n', 2);
  if ((str = malloc((len + data->count + 1) * sizeof(*str))) == NULL)
    return (NULL);
  if (data->str != 0)
    my_strncpy(str, data->str, len);
  my_strncpy(str, "", len);
  str[len + data->count] = 0;
  my_strncpy(str + len, stat->buf + stat->begin, data->count);
  if (data->str)
    free(data->str);
  stat->begin += (data->count  + 1);
  return (str);
}

char		*get_next_line(const int fd)
{
  static t_stat	stat;
  t_data	data;

  data.str = NULL;
  data.count = 0;
  while (42)
    {
      if (stat.ret_read <= stat.begin)
	{
	  stat.begin = 0;
	  if ((stat.ret_read = read(fd, stat.buf, READ_SIZE)) <= 0)
	    return (data.str);
	  stat.buf[stat.ret_read] = '\0';
	  data.count = 0;
	}
      if (stat.buf[stat.begin + data.count] == '\n')
	return (data.str = copy_str(&data, &stat));
      if (data.count + stat.begin  == stat.ret_read)
	{
	  data.str = copy_str(&data , &stat);
	  data.count = -1;
	}
      data.count++;
    }
  return (data.str);
}
