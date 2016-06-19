/*
** mesh.h for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 13:29:10 2016 Arthur Josso
** Last update Sat Apr 23 16:16:57 2016 Arthur Josso
*/

#ifndef MESH_H_
# define MESH_H_

# include "core.h"

typedef struct	s_nb_mesh
{
  int		v;
  int		vn;
  int		vt;
} t_nb_mesh;

int	mesh_pars(t_mesh *mesh);

int	mesh_add_v(t_mesh *mesh, char **val);
int	mesh_add_vn(t_mesh *mesh, char **val);
int	mesh_add_vt(t_mesh *mesh, char **val);
int	mesh_add_f(t_mesh *mesh, char **val, t_nb_mesh const *nb);

void    free_tab(char **tab);

#endif
