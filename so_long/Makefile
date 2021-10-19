all :
	@gcc -Imlx -c main.c 	get_next_line/get_next_line.c\
							get_next_line/get_next_line_utils.c\
							srcs/parse/parse_file.c\
							srcs/parse/check_correct_map.c\
							srcs/map_init.c\
							srcs/move_init.c\
							srcs/print_player.c\
							srcs/so_long_utils.c\
							srcs/parse/check_correct_map.c

	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit *.o libft.a -o so_long
	rm *.o


