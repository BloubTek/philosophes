/*
** philo.h for philo in /home/bloubtek/projets/philo
** 
** Made by morgane ferrandis
** Login   <ferran_m@epitech.eu>
** 
** Started on  Tue Mar 18 15:18:14 2014 morgane ferrandis
** Last update Tue Mar 18 15:22:23 2014 morgane ferrandis
*/

#ifndef PHILO_H_
# define PHILO_H_

typedef struct		s_baguette
{
  
}			t_baguette;

typedef struct		s_philo
{
  int			nb_philo;
  t_baguette		right;
  t_baguette		left;
  struct s_philo	*next;
}			t_philo;

#endif /* !PHILO_H_ */
