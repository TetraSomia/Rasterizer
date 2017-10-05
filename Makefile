##
## Makefile for rt in /home/josso/en_cours/rt
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Fri Jan 29 18:32:59 2016 Arthur Josso
## Last update Thu May 19 18:10:14 2016 Arthur Josso
##

NAME    =	rasterizer

CC	= 	gcc

INC     =       ./include/

CFLAGS 	+=	-I$(INC) -I/home/${USER}/.froot/include/ \
		-W -Wall -Wextra -O3

LDFLAGS +=	-L/home/${USER}/.froot/lib/ \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
                -lsfml-system -lstdc++ -ldl -lm

SRCS	=	./src/

INIT	=	./src/init/

LIGHT	=	./src/light/

CORE	=	./src/core/

MY	=	./src/my/

EXIT	=	./src/exit/

KEYS	=	./src/keys/

DISPLAY	=	./src/display/

MATRIX	=	./src/matrix/

SRC	= 	$(SRCS)main.c \
		$(DISPLAY)display.c \
		$(DISPLAY)fdf.c \
		$(DISPLAY)m2v.c \
		$(DISPLAY)rasterize.c \
		$(DISPLAY)rast_utils.c \
		$(MATRIX)utils.c \
		$(MATRIX)init.c \
		$(INIT)init.c \
		$(INIT)get.c \
		$(INIT)get2.c \
		$(INIT)load.c \
		$(INIT)add_cam.c \
		$(INIT)add_light.c \
		$(INIT)add_mesh.c \
		$(INIT)parsing.c \
		$(INIT)add_basic.c \
		$(INIT)add_face.c \
		$(CORE)tekpixel.c \
		$(CORE)vector.c \
		$(CORE)vector2.c \
		$(CORE)tekline.c \
		$(CORE)getpixel.c \
		$(EXIT)exit.c \
		$(KEYS)callback.c \
		$(KEYS)move.c \
		$(KEYS)height.c \
		$(KEYS)esc.c \
		$(KEYS)rotate.c \
		$(KEYS)action.c \
		$(MY)my_getnbr.c \
		$(MY)my_getdouble.c \
		$(MY)my_strcmp.c \
		$(MY)my_epurstr.c \
		$(MY)my_getnextline.c \
		$(MY)my_str_to_tab.c \
		$(MY)my_is_float.c \
		$(MY)my_isnbr.c

OBJ	= 	$(SRC:.c=.o)

RM	= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
