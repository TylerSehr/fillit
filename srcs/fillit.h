/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:31:38 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 09:50:05 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

# define REQUIRE(x, y) if (!x) return (y);

typedef	int			t_bool;
# define TRUE 1
# define FALSE 0

typedef struct		s_point
{
	int				x;
	int				y;
	char			value;
	struct s_point	*next;
	struct s_point	*start;
}					t_board;

int					fillit(char *input);
t_bool				validate_input(char **loaded_file, int output_pieces[26]);
char				**load_file(char *input_file);
void				print_input(char **loaded_file);
t_bool				run_validation(char **loaded_file, int output_pieces[26]);
t_bool				check_valid_input_format(char **loaded_file, int i, int j);
t_bool				check_pieces(char **loaded_file, int output_pieces[26]);
int					is_valid_piece(char *piece, int i, int j, int count);
char				*trim_piece(char const *s);
void				create_output(int output_pieces[26], int k, char *piece);
t_bool				build_solution(int output_pieces[26]);
t_bool				calculate_solution(int output_pieces[26]);
void				build_board(int pieces[26], t_board *board, int offset);
int					arraylen(int *array);
void				delete_piece(t_board *board, int piece_index);
t_bool				find_space(t_board *board, int piece_index, int index);
t_bool				find_solution(char **board, int output_pieces[26]);
void				pint_input(int *pieces);
int					square_root(int num);
void				swap(int *output_pieces, int start, int i);
void				clear_board(t_board *board);
int					get_next_line(const int fd, char **line);
int					find_first_location(char *s);
void				print_pieces(int output_pieces[26]);
void				print_board(t_board *board);
t_bool				place_piece(t_board *board, int piece_index, int index);
t_bool				place_point(t_board *board, int piece_i, int i, int index);
void				pint_pieces(int output_pieces[26]);
t_bool				run_calculation(int output_pieces[26], t_board *board);
t_bool				place_all(t_board *board, int output_pieces[26], int len);
int					*duplicate_array(int output_pieces[26], int *original);
t_bool				b(t_board *board, int pieces[26], int piece_index);
void				initialize_board(t_board *board, int x, int y);

#endif
