/*
** arena.c for arena in /home/bechad_p/rendu/PSU_2014_lemipc/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Mar  3 15:45:15 2015 Pierre Bechade
** Last update Sun Mar  8 18:43:17 2015 Pierre Bechade
*/

#include "lemipc.h"

int	is_arena_full(char **map)
{
  int	y;
  int	x;

  y = -1;
  x = -1;
  while (++y < M_SIZE_Y)
    {
      while (++x < M_SIZE_X)
	if (map[y][x] == '0')
	  return (1);
      x = -1;
    }
  return (0);
}

char	**fill_arena(char **map, t_share *share)
{
  int	bool;
  int	y;
  int	x;

  bool = 0;
  while (bool == 0)
    {
      y = rand() % M_SIZE_Y;
      x = rand() % M_SIZE_X;
      if (map[y][x] == '0')
        {
          map[y][x] = share->team + '0';
	  share->y = y;
	  share->x = x;
          bool = 1;
        }
    }
  return (map);
}

int	create_arena(t_share *share, int shm_id)
{
  int	z;
  int	y;

  if ((share->map = malloc(sizeof(char *)
			   * (M_SIZE_Y * M_SIZE_X))) == NULL)
    return (handle_error());
  z = -1;
  while (++z < M_SIZE_Y)
    share->map[z] = &((char *)share->addr)[M_SIZE_X * z];
  if (shm_id == -1)
    {
      z = -1;
      y = -1;
      while (++z < M_SIZE_Y)
	{
	  while (++y < M_SIZE_X)
	    share->map[z][y] = '0';
	  y = -1;
	}
    }
  else if (is_arena_full(share->map) == 0)
    return (EXIT_FAILURE);
  share->map = fill_arena(share->map, share);
  return (0);
}
