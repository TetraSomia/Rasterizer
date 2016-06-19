/*
** utils.c for matrix in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue May 10 11:41:15 2016 Arthur Josso
** Last update Mon May 16 15:17:47 2016 Arthur Josso
*/

#include <lapin.h>
#include "matrix.h"

void	mult_matrix(t_matrix *m1, t_matrix *m2, t_matrix *result)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (i < result->y)
    {
      j = 0;
      while (j < result->x)
	{
	  result->m[i][j] = 0;
	  k = 0;
	  while (k < result->y)
	    {
	      result->m[i][j] += m1->m[i][k] * m2->m[k][j];
	      k++;
	    }
	  j++;
	}
      i++;
    }
}

int	new_matrix(t_matrix *m, int x, int y)
{
  int	i;
  int	j;

  m->x = x;
  m->y = y;
  if ((m->m = bunny_malloc(sizeof(float*) * y)) == NULL)
    return (1);
  i = 0;
  while (i < y)
    {
      if ((m->m[i] = bunny_malloc(sizeof(float) * x)) == NULL)
	return (1);
      j = -1;
      while (++j < x)
	m->m[i][j] = i == j ? 1 : 0;
      i++;
    }
  return (0);
}

void	delete_matrix(t_matrix *m)
{
  int	i;

  i = 0;
  while (i < m->y)
    bunny_free(m->m[i++]);
  bunny_free(m->m);
}

void    free_mat_and_pt(t_matrix *m, t_matrix *pt)
{
  int   i;

  i = 0;
  while (i < NB_MATRICES)
    delete_matrix(&m[i++]);
  delete_matrix(&pt[0]);
  delete_matrix(&pt[1]);
}
