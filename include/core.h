/*
** core.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:23:59 2016 Arthur Josso
** Last update Thu May 12 18:06:10 2016 Arthur Josso
*/

#ifndef CORE_H_
# define CORE_H_

# include <lapin.h>

# define MAP(x, ba, ea, bb, eb) ((((ba - x) / (ba - ea)) * (eb - bb)) + bb)
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_vec
{
  float		x;
  float		y;
  float		z;
}		t_vec;

typedef struct	s_ray
{
  t_vec		alpha;
  t_vec		beta;
}		t_ray;

/*
** t_data
*/

typedef struct	s_cam
{
  t_vec		pos;
  t_vec		rot;
}		t_cam;

typedef struct		s_meta
{
  t_vec			pos;
  t_vec			rot;
  t_vec			scale;
  t_color		color;
  t_bunny_pixelarray	*tex;
}			t_meta;

typedef struct	s_vertex
{
  t_vec         *pos;
  t_vec         *n;
  t_vec         *t;
  int		i;
}		t_vertex;

typedef struct	s_tri_mesh
{
  t_vertex	vert[3];
}		t_tri_mesh;

typedef struct	s_mesh
{
  t_vec		**v;
  t_vec		*scr_pos;
  t_vec	       	**vn;
  t_vec	       	**vt;
  t_tri_mesh   	**tri;
  float		z_max;
  float		z_min;
  int	       	fd;
  t_meta       	meta;
}      		t_mesh;

typedef struct	s_light
{
  t_vec		pos;
  float		power;
} t_light;

typedef struct	s_nb_item
{
  int		light;
  int		mesh;
} t_nb_item;

typedef struct	s_obj
{
  t_nb_item     nb;
  t_light       *light;
  t_mesh	*mesh;
  t_cam         cam;
} t_obj;

typedef struct		s_data
{
  t_bunny_window        *win;
  t_bunny_pixelarray	*pix;
  float			**z_buff;
  t_obj                 obj;
  const bool		*keys;
} t_data;

typedef enum    e_exit
  {
    SUCCESS     = 0,
    ERROR       = 1
  }             t_exit;

#endif
