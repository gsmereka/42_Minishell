/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:36:43 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/04 19:36:39 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_data(t_data *data);

// Saida normal do minishell, atraves do ctrl + D ou do comando exit.
void	end_program(t_data *data) //comentarios em portugues
{
	int	exit_status;

	exit_status = data->exit_status;
	free_data(data);
	exit(exit_status);
}

// Saída pra quando houver algum erro interno,
// como falha na alocação de memorioa e etc...
void	exit_error(int error_value, char *msg, t_data *data)
{
	ft_printf("%s\n", msg);
	free_data(data);
	exit(error_value);
}

static void	free_data(t_data *data)
{
	if (data->dict_envp)
		dictclear(data->dict_envp);
	if (data->user_input)
		free(data->user_input);
	if (data->virtual_envp)
		free_array_list((void **)data->virtual_envp);
	rl_clear_history();
}

void	free_array_list(void **list)
{
	int i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}
