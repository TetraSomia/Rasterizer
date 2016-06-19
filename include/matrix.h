/*
** matrix.h for matrix in /home/josso/rendu/gfx/gfx_rasterizer
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue May 10 11:42:45 2016 Arthur Josso
** Last update Wed May 11 18:46:50 2016 Arthur Josso
*/

#ifndef MATRIX_H_
# define MATRIX_H_

# include "core.h"

# define NB_MATRICES	(8)

typedef struct	s_matrix
{
  int		x;
  int		y;
  float		**m;
}		t_matrix;

typedef struct	s_cosin
{
  t_vec		sin;
  t_vec		cos;
}		t_cosin;

void    show_matrix(t_matrix *m);

/*
** Utils
*/

int     new_matrix(t_matrix *m, int x, int y);
void	delete_matrix(t_matrix *m);
void    mult_matrix(t_matrix *m1, t_matrix *m2, t_matrix *result);

/*
** Setter
*/

void	set_cosin_values(t_meta *obj);
int     init_matrices(t_matrix *m, t_cam *cam, t_meta *obj);
int	init_pts(t_matrix *pt, t_vec *pos);
void	free_mat_and_pt(t_matrix *m, t_matrix *pt);

#endif
