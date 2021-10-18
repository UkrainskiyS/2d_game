all :
	@gcc -Imlx -c main.c mlx_utils/add_pixels.c\
						mlx_utils/make_trgb.c\
						mlx_utils/refactor_color.c\
						mlx_utils/hooks.c\
						get_next_line/get_next_line.c\
						get_next_line/get_next_line_utils.c\
						parse/parse_file.c\
						parse/map_init.c

	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit *.o libft.a -o so_long
	rm *.o


