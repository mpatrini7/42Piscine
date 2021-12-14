/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:23 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 23:28:32 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		obstacle_found_col(int **arr, int col, int row, int pos[3]);
int		obstacle_found_row(int **arr, int col, int row, int pos[3]);
int		square_check2(int **arr, int pos[3], int s_pos[2]);
void	square_check(int **arr, int pos[3], int size[2], int temp_pos[3]);
void	the_square_game2(int final_pos[3], int max[2], int temp_pos[3]);
void	the_square_game(int **arr, int size[2], int final_pos[3]);
void	error_map(void);
void	see_map(char *file);
int		lenstr(char*str);
int		**make_matrix(int row, int col);
void	ft_swap(char *a, char *b);
void	rev_line(char *tab, int size);
char	**generate_file_tab(char *file, int *row, int *col);
int		fill_tab(char *file, char **tab, int col, int first_row);
int		get_rows_cols(char *file, int *rows, int *cols);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_square(char **map, int *square, char *var, int *cord);
void	convert_arr(char **map, int **vins, char *var, int *cord);
int		approve_number(char *line);
int		need_for_approval(char **table, int row, int col);
char	*tastiera(char *input);
void	main2(void);
int		approve_legend(char *line);
int		approve_char(char **table, char *legend, int row, int col);
void	fill_tab2(int *mix, char buffer, int first_row, char **tab);
void	libera_tab(int **tab, int num_righe);
void	libera_tab2(char **tab, int num_righe);

#endif
