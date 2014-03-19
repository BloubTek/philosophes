/*
** actions.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes/philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Wed Mar 19 12:34:10 2014 severine roy
** Last update Wed Mar 19 16:47:35 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

void		give_stick(t_philo *p)
{
  int		to_use;

  to_use = 1;
  while (to_use != 0)
    {
      if (p->left == IS_NOT_USED)
	{
	  p->left = IS_USED;
	  to_use--;
	}
      else if (p->right == IS_NOT_USED)
	{
	  p->right = IS_USED;
	  to_use--;
	}
      p = p->next;
      if (p)
	p = p->head;
    }
}

void		*eat(void *p)
{
  t_philo	*philo;

  philo = (t_philo*)p;
  printf("Philosophe %d is eating\n", philo->nb_philo);
  //sleep(2);
  //  printf("Philosophe %d stopped eating\n", philo->nb_philo);
  philo->left = IS_NOT_USED;
  philo->right = IS_NOT_USED;
  philo->life -= 10;
  philo->etat = EAT;
  give_stick(philo->next);
  pthread_exit(NULL);
}

void		*think(void *p)
{
  t_philo       *philo;

  philo = (t_philo*)p;
  printf("Philosophe %d is thinking\n", philo->nb_philo);
  //sleep(2);
  //printf("Philosophe %d stopped thinking\n", philo->nb_philo);
  philo->right = IS_NOT_USED;
  philo->etat = THINK;
  philo->life -= 10;
  give_stick(philo->next);
  pthread_exit(NULL);
}

void		*rest(void *p)
{
  t_philo       *philo;

  philo = (t_philo*)p;
  printf("Philosophe %d is sleeping\n", philo->nb_philo);
  philo->etat = SLEEP;
  //sleep(2);
  //printf("Philosophe %d stopped sleeping\n", philo->nb_philo);
  philo->life -= 10;  
  pthread_exit(NULL);
}
