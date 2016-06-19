/*
** load.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 16:12:39 2016 Arthur Josso
** Last update Sat May 21 16:30:10 2016 Arthur Josso
*/

#include "init.h"
#include "my.h"

static t_parsing	g_func[] =
  {
    {&add_cam, "camera"},
    {&add_light, "light"},
    {&add_mesh, "mesh"},
    {NULL, NULL}
  };

static int	get_type(t_obj *obj, t_bunny_ini_scope *scope)
{
  const char    *type;
  int           i;

  if ((type = bunny_ini_scope_get_field(scope, "type", 0)) == NULL)
    return (1);
  i = 0;
  while (g_func[i].name)
    {
      if (my_strcmp((char*)type, g_func[i].name) == 0)
	{
	  if (((g_func[i].func)(obj, scope)) == 1)
	    return (1);
	  else
	    return (0);
	}
      i++;
    }
  return (1);
}

static int              get_scope(t_obj *obj, t_bunny_ini *file)
{
  t_bunny_ini_scope     *scope;

  if ((scope = bunny_ini_first(file)) == NULL)
    return (1);
  while ((scope = bunny_ini_next(file, scope)) != NULL)
    if (get_type(obj, scope) == 1)
      return (1);
  return (0);
}

int		load_scene(t_obj *obj, const char *file)
{
  t_bunny_ini   *ini;

  obj->nb.light = 0;
  obj->nb.mesh = 0;
  if ((ini = bunny_load_ini(file)) == NULL)
    return (ERROR);
  if (get_scope(obj, ini) == 1)
    return (ERROR);
  bunny_delete_ini(ini);
  return (SUCCESS);
}
