/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:02:39 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/04 19:39:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	identify_flags(int *n_flag, char **args);
static void	display_text_line(int *n_flag, char **args);

// Se o primeiro argumento for -n, ele retira a quebra de linha no final.
void	ft_echo(char **args, t_data *data)
{
	int	n_flag;

	n_flag = 0;
	if (!args || !args[1])
		return ;
	identify_flags(&n_flag, args);
	display_text_line(&n_flag, args);
	(void)data;
}

static void	identify_flags(int *n_flag, char **args)
{
	if (ft_strncmp(args[1], "-n", 2) == 0)
		*n_flag = 1;
}

static void	display_text_line(int *n_flag, char **args)
{
	int	i;

	i = 1;
	if (*n_flag)
		i++;
	while (args[i])
	{
		write(1, args[i], ft_strlen(args[i]));
		if (args[i + 1])							 // se ainda não for a ultima palavra
			write(1, " ", 1);
		i++;
	}
	if (*n_flag == 0) 						// se o primeiro argumento for -n
		write(1, "\n", 1);
}
