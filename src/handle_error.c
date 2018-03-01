/*
** handle_error.c for handle_error in /home/bechad_p/rendu/PSU_2014_lemipc/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Mar  3 15:42:20 2015 Pierre Bechade
** Last update Sun Mar  8 19:30:15 2015 Pierre Bechade
*/

#include "lemipc.h"

int	handle_error()
{
  perror("lemipc error : ");
  return (EXIT_FAILURE);
}

int	map_error()
{
  write(2, "lemipc error : map is full.\n", 28);
  return (EXIT_FAILURE);
}

void	*xmalloc(size_t size)
{
  void	*res;

  if ((res = malloc(size)) == NULL)
    exit(0);
  return (res);
}
