/*
** check.c for check in /home/bechad_p/rendu/PSU_2014_lemipc/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Mar  8 18:33:36 2015 Pierre Bechade
** Last update Sun Mar  8 18:56:18 2015 Pierre Bechade
*/

#include "lemipc.h"

int	is_border(t_share *share, int x, int y)
{
  if (x < 0 || x >= M_SIZE_X)
    return (-1);
  else if (y < 0 || y >= M_SIZE_Y)
    return (-1);
  else if ((x == share->x) && (y == share->y))
    return (-1);
  return (0);
}

int	is_empty(t_share *share, int x, int y)
{
  if (is_border(share, x, y) == -1)
    return (-1);
  else if (share->map[y][x] == '0')
    return (0);
  return (-1);
}

int	is_dead(t_share *share)
{
  char	*str;
  int	i;
  int	x;
  int	y;

  if ((str = malloc(sizeof(char) * 10)) == NULL)
    exit(0);
  (1) ? x = share->x - 1, y = share->y - 1 : 0;
  i = -1;
  while (++i < 9)
    {
      if (is_border(share, x, y) != -1)
        str[i] = share->map[y][x];
      else
        str[i] = '0';
      if (i == 2 || i == 5)
        {
          x = share->x - 1;
          y = y + 1;
        }
      else
        x = x + 1;
    }
  str[i] = '\0';
  return (check_str(str, share));
}
