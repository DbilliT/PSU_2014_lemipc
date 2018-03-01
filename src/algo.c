/*
** algo.c for algo in /home/bechad_p/rendu/PSU_2014_lemipc/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Mar  3 15:55:25 2015 Pierre Bechade
** Last update Sun Mar  8 19:08:33 2015 Pierre Bechade
*/

#include "lemipc.h"

int	check_str(char *str, t_share *share)
{
  char	c;
  int	i;

  c = 0;
  i = 1;
  if (str[0] == '0' || str[0] == share->team + '0')
    return (check_str(str + 1, share));
  else if (str[0] == '\0')
    {
      (strlen(str) == 9) ? free(str) : 0;
      return (0);
    }
  else
    c = str[0];
  while (str[i])
    {
      if (str[i] == c)
  	{
  	  if (strlen(str) == 9)
  	    free(str);
  	  return (-1);
  	}
      i++;
    }
  return (check_str(str + 1, share));
}

int	search_kill(t_share *share)
{
  int	x_rand;
  int	y_rand;

  x_rand = 1000;
  y_rand = 1000;
  while (is_border(share, share->x
		   + x_rand, share->y + y_rand) == -1
	 || is_empty(share, share->x
		     + x_rand, share->y + y_rand) == -1)
    {
      x_rand = (rand() % 3) - 1;
      y_rand = (rand() % 3) - 1;
    }
  share->map[share->y][share->x] = '0';
  share->map[share->y + y_rand][share->x + x_rand]
    = share->team + '0';
  share->x = share->x + x_rand;
  share->y = share->y + y_rand;
  return (0);
}

int	is_winner(t_share *share)
{
  char	c;
  int	x;
  int	y;

  c = 0;
  x = -1;
  y = -1;
  while (++y < M_SIZE_Y)
    {
      while (++x < M_SIZE_X)
	{
	  if (share->map[y][x] != '0')
	    {
	      if (c != 0 && share->map[y][x] != c)
		return (0);
	      c = share->map[y][x];
	    }
	}
      x = -1;
    }
  return (-1);
}

int	life(t_share *share)
{
  while (42)
    {
      usleep(100000);
      if (is_winner(share) == -1)
      	{
      	  if ((shmctl(share->shm_id, IPC_RMID, NULL)) == -1)
	    return (handle_error());
	  printf("The winner is the team :");
	  printf(" %c\n", share->team + '0');
      	  free(share);
      	  return (0);
      	}
      if (is_dead(share) == -1)
	{
	  share->map[share->y][share->x] = '0';
	  printf("A player from the team :");
	  printf(" %c is dead\n", share->team + '0');
	  free(share);
	  return (0);
	}
      search_kill(share);
    }
  return (0);
}
