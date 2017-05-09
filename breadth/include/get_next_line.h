/*
** get_next_line.h for getnextline in /home/tahery_b/rendu/
** 
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
** 
** Started on  Fri Jan  6 15:02:47 2017 Tahery Alexandre
** Last update Thu Jan 19 07:00:20 2017 Alexandre Tahery
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

#ifndef READ_SIZE
# define READ_SIZE (5)
#endif /* !READ_SIZE */

typedef struct		s_stat
{
  char			buf[READ_SIZE + 1];
  int			ret_read;
  int			begin;
}			t_stat;

typedef struct		s_data
{
  char			*str;
  int			count;
}			t_data;

char			*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
