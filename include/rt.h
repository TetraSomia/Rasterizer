/*
** rt.h for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:34:35 2016 Arthur Josso
** Last update Thu May 19 17:16:24 2016 Arthur Josso
*/

#ifndef RT_H_
# define RT_H_

# include "core.h"

# define FULL_SCR (0)
# define W_X (800)
# define W_Y (800)
# define FPS (30)

/*
** Initialization
*/

int	load_scene(t_obj *obj, const char *file);
int     init(t_data *data, const char *file);

/*
** Display
*/

int     gen_scene(t_data *data);
int     get_screen_pos(t_data *data, t_mesh *mesh);
void	fdf(t_data *data, t_mesh *mesh);
void    zbuff(t_data *data, t_mesh *mesh);
int	rasterize(t_data *data, t_mesh *mesh);

/*
** Rasterize
*/

typedef struct		s_bounds
{
  t_bunny_position	min;
  t_bunny_position	max;
}			t_bounds;

float   edge(t_vec *v1, t_vec *v2, t_vec *p);
t_vec   get_bary_coef(t_vec *pix, t_mesh *mesh, t_tri_mesh *tri);
void    resize(t_bunny_position *p);
float   get_depth(t_mesh *mesh, t_tri_mesh *tri, t_vec *area);
t_vec   get_tex_coord(t_tri_mesh *tri, t_vec *area);

/*
** Math
*/

# define POW(x) ((x) * (x))

void    set_uni_vec(t_vec *v);
float   get_norm(float k, t_vec *vec);
t_vec   get_vec(t_vec *pt1, t_vec *pt2);
t_vec   get_uni_vec(t_vec *pt1, t_vec *pt2);
float   get_dot(t_vec *v1, t_vec *v2);
t_vec	vec_product(t_vec *u, t_vec *v);
void    inv_vec(t_vec *v);
void	mult_vec(float x, t_vec *v);

/*
** Preview
*/

# define MOVE (0.1)
# define ROT (M_PI / 128)

void    interact_cam(t_cam *cam);

/*
** Core
*/

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *p,
		 t_color *c);
void	put_pixel(t_bunny_pixelarray *pix,
		  t_vec *p,
		  t_color *c);
void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *coord,
		t_color *color);
t_color get_color(t_color *src, float coef);
t_color get_pixel(t_bunny_pixelarray *pix, t_vec *pos);
void    put_in_black(t_bunny_pixelarray *pix);

/*
** Exit
*/

void	exit_prog(t_data *data);

#endif
