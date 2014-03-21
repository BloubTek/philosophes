/*
** main.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Tue Mar 18 14:00:59 2014 severine roy
** Last update Fri Mar 21 19:32:56 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

# define NB_PHILO  7

int	rice = 10;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void			*loop_philo(void  *t)
{
  t_philo		*p;
  static int		i = 1;

  p = (t_philo*)t;
  while (42)
    {
      //pthread_mutex_lock(&m);	
      while (rice > 0)
	{
	  
	  /* if (p->etat == THINK) */
	  /*   { */
	  /*     if (p->right == IS_USED && p->left == IS_USED) */
	  /* 	eat(p); */
	  /*   } */
	  if (p->right == IS_USED && p->left == IS_USED)
	    eat(p);
	  else if (p->right == IS_USED || p->left == IS_USED)
	    think(p);
	  else if (p->right == IS_NOT_USED && p->left == IS_NOT_USED)
	    rest(p);
	  i++;
	  //pthread_mutex_unlock(&m);	
	}
      return (t);
    }
  return (t);
}

t_philo			*init_philo(t_philo *p)
{
  t_philo		*p2;
  int			i;
  int			stick;

  p2 = p;
  i = 0;
  stick = NB_PHILO;
  while (i < NB_PHILO)
    {
      if ((p2->next = malloc(sizeof(*p))) == NULL)
	return (p);
      p2->next->prev = p2;
      p2->life = 100;
      p2->etat = SLEEP;
      p2->right = IS_NOT_USED;
      p2->left = IS_NOT_USED;
      p2->nb_philo = i;
      p2->head = p;
      if (stick && i%2 == 0)
	{
	  p2->left = IS_USED;
	  stick--;
	}   
      if (stick && i%2 == 0)
	{
	  p2->right = IS_USED;
	  stick--;
	}   
      if (i == 6)
	{
	  p2->next = p;
	  p->prev = p2;	
	}
      else
	p2 = p2->next;
      ++i;
    }
  return (p);
}

void		loop(t_philo *p)
{
  t_philo		*tmp;
  int			i;
  pthread_t		t[NB_PHILO];
  
  i = 0;
  tmp = p;
  while (i < NB_PHILO)
    {
      if ((pthread_create(&t[i], NULL, &loop_philo, tmp)) != 0)
    return ;
      tmp = tmp->next;
      i++;
    }
  i = 0;
  while (i < NB_PHILO)
    {
      pthread_join(t[i], NULL);
      ++i;
    }
  printf("-------------------------------------------\n");
}

int			main()
{
  t_philo		*p;
  
  if ((p = malloc(sizeof(*p))) == NULL)
    return (-1);
  p = init_philo(p);
  loop(p);
  return (0);
}

