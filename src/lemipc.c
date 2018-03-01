/*
** lemipc.c for lemipc in /home/bechad_p/rendu/PSU_2014_lemipc/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Feb 26 16:57:26 2015 Pierre Bechade
** Last update Sun Mar  8 19:31:09 2015 Pierre Bechade
*/

#include "lemipc.h"

key_t		rep_key(t_share *share, int team)
{
  key_t		key;
  char		path[4096];

  if ((getcwd(path, 4096)) == NULL)
    exit(0);
  if ((key = ftok(path, 0)) == -1)
    return (handle_error());
  share->team = team;
  share->key = key;
  return (key);
}

int		lemipc(int team)
{
  t_share	*share;
  int		shm_id;

  share = xmalloc(sizeof(t_share));
  rep_key(share, team);
  if ((shm_id = shmget(share->key,
		       M_SIZE_Y * M_SIZE_X, SHM_R | SHM_W)) == -1)
    {
      if ((shm_id = shmget(share->key, (M_SIZE_Y * M_SIZE_X),
			   IPC_CREAT | SHM_R | SHM_W)) == -1)
	return (handle_error());
      if ((share->addr = shmat(shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
	return (handle_error());
      if (create_arena(share, -1) == EXIT_FAILURE)
	return (map_error());
    }
  else
    {
      if ((share->addr = shmat(shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
	return (handle_error());
      if (create_arena(share, shm_id) == EXIT_FAILURE)
	return (map_error());
    }
  share->shm_id = shm_id;
  return (life(share));
}

int	main(int ac, char **av)
{
  srand(time(NULL));
  if (ac == 1)
    return (lemipc(1));
  if (ac > 2)
    {
      printf("USAGE : %s TEAM\n", av[0]);
      return (EXIT_FAILURE);
    }
  return (lemipc(atoi(av[1])));
}
