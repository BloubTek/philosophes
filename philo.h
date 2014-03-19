/*
** philo.h for philo in /home/bloubtek/projets/philo
** 
** Made by morgane ferrandis
** Login   <ferran_m@epitech.eu>
** 
** Started on  Tue Mar 18 15:18:14 2014 morgane ferrandis
** Last update Wed Mar 19 14:50:08 2014 severine roy
*/

#ifndef PHILO_H_
# define PHILO_H_

typedef			enum
{
  IS_USED,
  IS_NOT_USED
  
}			e_stick;

typedef			enum
{
  SLEEP,
  THINK,
  EAT
}			e_etat;
  
typedef struct		s_philo
{
  int			nb_philo;
  int			life;
  e_etat		etat;
  e_stick		right;
  e_stick		left;
  struct s_philo	*next;
  struct s_philo	*head;
}			t_philo;


void		*eat(void *);
void		*think(void *);
void		*rest(void *);

#endif /* !PHILO_H_ */
