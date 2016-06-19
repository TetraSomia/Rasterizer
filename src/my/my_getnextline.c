/*
** get_next_line.c for get_next_line in /home/josso/rendu/cpe/CPE_2015_getnextline
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 12 19:08:58 2016 Arthur Josso
** Last update Thu Apr 21 16:12:11 2016 Arthur Josso
*/

#include <unistd.h>
#include "my.h"

static int	cut_remainder(char **remain, int *len, int pos)
{
  char		*buff;
  int		i;

  if ((buff = bunny_malloc(*len - pos)) == NULL)
    return (-1);
  i = pos;
  while (i < *len)
    {
      buff[i - pos] = (*remain)[i];
      i++;
    }
  bunny_free(*remain);
  *remain = buff;
  *len -= pos;
  return (0);
}

static char	*cut_line(char **remain, int *len, int pos)
{
  int		i;
  char		*ret;

  if (*remain == NULL)
    return (NULL);
  if ((ret = bunny_malloc(pos + 1)) == NULL)
    return (NULL);
  i = -1;
  while (++i < pos)
    ret[i] = (*remain)[i];
  ret[i] = '\0';
  if (*len == pos + 1)
    {
      bunny_free(*remain);
      *remain = NULL;
      *len = 0;
      return (ret);
    }
  else if (cut_remainder(remain, len, pos + 1) == -1)
    return (NULL);
  return (ret);
}

static char	*getline(char **remain, int *len, int end)
{
  int		i;
  char		*ret;

  if (*remain == NULL)
    return (NULL);
  i = -1;
  if (!end)
    {
      while (++i < *len)
	if ((*remain)[i] == '\n')
	  return (cut_line(remain, len, i));
      return (NULL);
    }
  if ((ret = bunny_malloc(*len + 1)) == NULL)
    return (NULL);
  while (++i < *len)
    ret[i] = (*remain)[i];
  ret[i] = '\0';
  bunny_free(*remain);
  *remain = NULL;
  *len = 0;
  return (ret);
}

static int	add_buff(char **remain, int *len, char *buff, int buff_len)
{
  char		*new;
  int		i;
  int		size;

  size = *len + buff_len;
  if ((new = bunny_malloc(size)) == NULL)
    return (-1);
  i = 0;
  while (i < size)
    {
      if (i < *len)
	new[i] = (*remain)[i];
      else
	new[i] = buff[i - *len];
      i++;
    }
  if (*remain)
    bunny_free(*remain);
  *remain = new;
  *len = size;
  return (0);
}

char		*get_next_line(int fd)
{
  static char	*remainder;
  static int	len;
  char		*ret;
  char		buff[READ_SIZE];
  int		len_read;

  while ((ret = getline(&remainder, &len, 0)) == NULL)
    {
      if ((len_read = read(fd, buff, READ_SIZE)) == -1)
	return (NULL);
      if (len_read == 0)
	  return (getline(&remainder, &len, 1));
      else if (add_buff(&remainder, &len, buff, len_read) == -1)
	return (NULL);
    }
  return (ret);
}
