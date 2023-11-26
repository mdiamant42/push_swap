/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:40:10 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

void	creat_list(t_list **a, char **argv);
char	**make_argv(int argc, char **argv);
void	free_argv(char **argv);
void	verif_end(t_list *a);
void	ra(t_list **a);
void	pa(t_list **a, t_list **b);
void	sa(t_list **a);
void	rra(t_list **a);
void	found_conditions(int argc, char **argv, int i);
int		found_double(char **argv);
int		found_int(char **argv);
int		found_char(char **argv);
void	checker(char **argv, char *line);
int		checker_1(t_list **a, t_list **b, char *line);
int		checker_2(t_list **a, t_list **b, char *line);
int		checker_3(t_list **a, t_list **b, char *line);

#endif
