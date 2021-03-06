/*
** actions.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes/philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Wed Mar 19 12:34:10 2014 severine roy
** Last update Fri Mar 21 16:43:48 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

extern int	rice;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void		give_stick(t_philo *p)
{
  int		to_use;

  to_use = 1;
  while (to_use != 0)
    {
      if (p->prev->etat == THINK && p->prev->right == IS_NOT_USED)
	{
	  p->prev->right = IS_USED;
	  to_use = 0;
	}
      else if (p->next->left == IS_NOT_USED)
	{
	  p->next->left = IS_USED;
	  to_use = 0;
	}
      else
	{
	  p->prev->right = IS_USED;
	  to_use = 0;
	}
    }
}

void		eat(void *p)
{
  t_philo	*philo;
  pthread_mutex_lock(&m2);

  if (rice > 0)
    {
      philo = (t_philo*)p;
      printf("Philosophe %d is eating\n", philo->nb_philo);
      sleep(1);
      philo->right = IS_NOT_USED;
      philo->left = IS_NOT_USED;
      rice--;
      printf("rice : %d\n", rice);
      philo->etat = EAT;
      give_stick(philo);
      give_stick(philo);
    }
  pthread_mutex_unlock(&m2);
}

void		think(void *p)
{
  t_philo       *philo;

  philo = (t_philo*)p;
  printf("Philosophe %d is thinking\n", philo->nb_philo);
  sleep(1);
  philo->etat = THINK;
}

void		rest(void *p)
{
  t_philo       *philo;

  philo = (t_philo*)p;
  printf("Philosophe %d is sleeping\n", philo->nb_philo);
  philo->etat = SLEEP;
  sleep(1);
}
