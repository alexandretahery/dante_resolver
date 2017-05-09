/*
** depth_dante.h for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 09:38:18 2017 Alexandre Tahery
** Last update Fri Apr 28 11:14:27 2017 Alexandre Tahery
*/

#ifndef DEPTH_DANTE_H_
# define DEPTH_DANTE_H_

#define CHAR_WALL 'X'
#define TRUE 0
#define FALSE -1
#define FAIL 84
#define FAIL_N -1
#define SUCCESS 0
#define VISITED 42
#define NO_VISITED 666
#define WAY_NO_FUND 666
#define WAY_FUND 42

typedef struct          s_2int
{
  int                   x;
  int                   y;
}                       t_2int;

typedef struct		s_array_node
{
  int			walk;
  int			visited;
  struct s_array_node	*father;
  struct s_array_node	*next;
  t_2int		pos;
}			t_array_node;

typedef struct	s_data_mazes
{
  char		**array_char;
  t_array_node	**array_node;
  t_2int	pos_begin;
  t_2int	pos_end;
  int		find_path;
  int		x;
  int		y;
}		t_data_mazes;

int		my_strlen(char *str);
int		my_strlen_tab(char **tab);
char		**field_char(char *argv);
int		field_node(t_data_mazes *data_mazes);
void		set_pos(t_data_mazes *data_mazes);
void		display_tab(char **map);
t_array_node	*put_end_of_list(t_array_node *list,
				 t_array_node *elem,
				 t_array_node *top);
t_array_node	*delete_begin_of_list(t_array_node *list);
#endif /* !DEPTH_DANTE_H_ */
