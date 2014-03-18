/*
** philo.h for philo in /home/bloubtek/projets/philo
** 
** Made by morgane ferrandis
** Login   <ferran_m@epitech.eu>
** 
** Started on  Tue Mar 18 15:18:14 2014 morgane ferrandis
** Last update Tue Mar 18 15:41:41 2014 severine roy
*/

#ifndef PHILO_H_
# define PHILO_H_

typedef			enum
{
  IS_USED,
  IS_NOT_USED
  
}			stick;

typedef struct		s_philo
{
  int			nb_philo;
  stick			right;
  stick			left;
  struct s_philo	*next;
}			t_philo;

#endif /* !PHILO_H_ */
