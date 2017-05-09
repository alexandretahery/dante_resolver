/*
** depth_dante.h for dante in /home/alexandre/rendu/2016/CPE/dante/depth_src
** 
** Made by Alexandre Tahery
** Login   <alexandre1.tahery@epitech.eu>
** 
** Started on  Wed Apr 19 09:38:18 2017 Alexandre Tahery
** Last update Mon Apr 24 17:17:26 2017 Alexandre Tahery
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
void		depth_condition(t_data_mazes *data_mazes,
				int x,
				int y,
				int found);
int		depth_search(t_data_mazes *data_mazes,
			     int x,
			     int y,
			     t_array_node *top);
void		display_tab(char **map);

#endif /* !DEPTH_DANTE_H_ */
