NAME =		so_long

SRCS = 		main.c srcs/gnl/get_next_line.c\
					srcs/gnl/get_next_line_utils.c\
					srcs/parse/parse_file.c\
                    srcs/parse/check_correct_map.c\
                    srcs/map_init.c\
                    srcs/move_init.c\
                    srcs/print_player.c\
                 	srcs/so_long_utils.c\

OBJS = 		$(SRCS:.c=.o)

FLAGS =		-Wall -Wextra -Werror

MLX_FLAGS =	-Lmlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	make -C mlx/
	@cp mlx/libmlx.dylib ./
	gcc $(FLAGS) $(MLX_FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -Imlx -c $< -o $@

clean :
	make fclean -C libft/
	make clean -C mlx/
	@rm -f $(OBJS)

fclean : clean
	@rm -f libmlx.dylib
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
