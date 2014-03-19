/*
** main.c for philosophes in /home/roy_s/Local/Systeme_Unix/Philosophes
** 
** Made by severine roy
** Login   <roy_s@epitech.net>
** 
** Started on  Tue Mar 18 14:00:59 2014 severine roy
** Last update Wed Mar 19 16:45:04 2014 severine roy
*/

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

# define NB_PHILO  7

void			loop_philo(t_philo *p)
{
  t_philo		*p2;
  pthread_t		t;

  p2 = p;
  p->head = p2; 
  while (42)
    {
      while (p)
	{
	  printf("life: %d\n", p->life);
	  if (p->life > 9)
	    if (p->right == IS_USED && p->left == IS_USED)
	      {
		if ((pthread_create(&t, NULL, &eat, p)) != 0)
		  printf("bloub\n");
	      }
	    else if (p->etat == EAT && (p->left == IS_USED || p->right == IS_USED))
	      {	      
		if ((pthread_create(&t, NULL, &think, p)) != 0)
		  printf("oiseau crevette\n");
	      }
	    else
	      {
		if ((pthread_create(&t, NULL, &rest, p)) != 0)
		  printf("fouff\n");
	      }
	  p = p->next;
	  //  pthread_join(t, NULL);
	}
      printf("laaaaa\n");
      sleep(5);
      p = p2;
    }
}

void			init_philo(t_philo *p)
{
  t_philo		*p2;
  int			i;
  int			stick;

  i = 1;
  stick = NB_PHILO - 2;
  p->left = IS_USED;
  p->right = IS_USED;
  p->nb_philo = 0;
  p->etat = SLEEP;
  p->life = 100;
  while (i < 7)
    {
      p2 = malloc(sizeof(t_philo));
      p2->nb_philo = i;
      p2->left = IS_NOT_USED;
      p2->right = IS_NOT_USED;
      p2->etat = SLEEP;
      p2->life = 100;
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
      p->next = p2;
      p = p2;
      ++i;
    }
}

int			main()
{
  t_philo		p;
  
  init_philo(&p);
  loop_philo(&p);
}

