/*
** get_next_line.h for dante in /home/alexandre/rendu/2016/CPE/dante/astar
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:52:12 2017 Alexandre Tahery
** Last update Fri Apr 28 12:52:50 2017 Alexandre Tahery
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

#ifndef READ_SIZE
# define READ_SIZE (4000000)
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
