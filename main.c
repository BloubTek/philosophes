/*
** main.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Tue Mar 18 14:00:59 2014 severine roy
** Last update Wed Mar 19 20:04:51 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

# define NB_PHILO  7

void			*loop_philo(void  *t)
{
  t_philo		*p;
 
  p = (t_philo*)t;
  if (p->life > 9)
    {
      printf("life: %d\n", p->life);
      printf("philo %d a bg: %d, %d\n", p->nb_philo, p->left, p->right);
      if (p->right == IS_USED && p->left == IS_USED)
	eat(p);
      else if (p->etat == EAT && (p->left == IS_USED || p->right == IS_USED))
	think(p);
      else
	rest(p);
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
      p2->next = malloc(sizeof(*p));
      p2->life = 100;
      p2->etat = SLEEP;
      p2->right = IS_NOT_USED;
      p2->left = IS_NOT_USED;
      p2->nb_philo = i;
       if (stick)
	{
	  p2->left = IS_USED;
	  --stick;
	}
      if (stick)
	{
	  p2->right = IS_USED;
	  --stick;
	}
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
  
  while (42)
    {
      i = 0;
      tmp = p;
      while (i < NB_PHILO)
	{
	  pthread_create(&t[i], NULL, &loop_philo, tmp);
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
}

int			main()
{
  t_philo		*p;
  
  p = malloc(sizeof(*p));
  p = init_philo(p);
  loop(p);
  return (0);
}

