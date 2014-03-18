/*
** main.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Tue Mar 18 14:00:59 2014 severine roy
** Last update Tue Mar 18 15:18:47 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>

# define NB_PHILO  7

void		*loop(void *name)
{
  printf("%d\n", *(int*)name);
}

int		main()
{
  pthread_t	p[NB_PHILO];
  int		name[NB_PHILO];
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      name[i] = i;
      if (pthread_create(&p[i], NULL, loop, &name[i]) != 0)
	{
	  printf("Create thread error\n");
	  return (-1);
	}
      ++i;
    }
  i = 0;
  while (i < NB_PHILO)
    {
      pthread_join(p[i], NULL);
      ++i;
    }
  return (0);
}
