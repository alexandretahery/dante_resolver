/*
** astar.h for dante in /home/alexandre/rendu/2016/CPE/dante/astar
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Fri Apr 28 12:51:58 2017 Alexandre Tahery
** Last update Fri Apr 28 13:23:48 2017 Alexandre Tahery
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# define FAIL_N -1
# define FAIL 84
# define SUCCESS 0
# define CHAR_WALL 'X'
# define CHAR_WAY '*'
# define VAL_BEGIN -4
# define VAL_END -2
# define VAL_WALL -1
# define VAL_WAY 0
# define TRUE 0
# define FALSE 1
# define RET_NODE1 1
# define RET_NODE2 -1
# define X_POS 0
# define Y_POS 1
# define CLOSE_LIST 666
# define OPEN_LIST 42
# define NONE_LIST 69

typedef struct		s_2int
{
  int			x;
  int			y;
}			t_2int;

typedef struct		s_array_node
{
  int			walk;
  int			list;
  int			g;
  int			h;
  int			f;
  t_2int		pos;
  int			x_father;
  int			y_father;
  struct s_array_node	*father;
  struct s_array_node	*list_p;
}			t_array_node;

typedef struct		s_data_map
{
  int			x;
  int			y;
  int			pos_begin[2];
  int			pos_end[2];
  char			**array_char;
  t_array_node		**array_node;
  t_array_node		*open_list;
  t_array_node		*way;
}			t_data_map;

int		my_strlen(char *str);
int		my_strlen_tab(int **tab);
void		free_tab(void **tab);
int		my_getnbr(char *str);
int		field_node(t_data_map *data_map);
char		**field_char(char *argv);
void		set_pos(t_data_map *data_map);
int		find_little_f(t_data_map *data_map);
void		a_star(t_data_map *data_map);
void		display_tab(char **map);

#endif /* !ASTAR_H_ */
