all :
	@gcc -Imlx -c main.c 	get_next_line/get_next_line.c\
							get_next_line/get_next_line_utils.c\
							srcs/parse/parse_file.c\
							srcs/parse/map_init.c\
							srcs/move/move_init.c\
							srcs/print/print_player.c

	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit *.o libft.a -o so_long
	rm *.o


