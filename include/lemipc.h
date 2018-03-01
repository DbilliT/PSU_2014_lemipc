/*
** lemipc.h for lemipc in /home/bechad_p/rendu/PSU_2014_lemipc/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Feb 26 16:49:27 2015 Pierre Bechade
** Last update Sun Mar  8 19:30:44 2015 Pierre Bechade
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

# define M_SIZE_X 20
# define M_SIZE_Y 20
# define NB_PLAYER 4
# define ERROR -1

typedef struct	s_share
{
  int		team;
  key_t		key;
  int		shm_id;
  void		*addr;
  char		**map;
  int		x;
  int		y;
}		t_share;
/* IN SRC/ALGO.C */
int	check_str(char *str, t_share *share);
int	search_kill(t_share *share);
int	is_winner(t_share *share);
int	life(t_share *share);
/* IN SRC/LEMIPC.C */
int	rep_key(t_share *share, int team);
int	lemipc(int team);
/* IN SRC/HANDLE_ERROR.C */
void	*xmalloc(size_t size);
int	handle_error();
int	map_error();
/* IN SRC/ARENA.C */
int	is_arena_full(char **map);
char	**fill_arena(char **map, t_share *share);
int	create_arena(t_share *share, int shm_id);
/* IN SRC/CHECK.C */
int	is_border(t_share *share, int x, int y);
int	is_empty(t_share *share, int x, int y);
int	is_dead(t_share *share);
#endif /* LEMIPC_H_ */
