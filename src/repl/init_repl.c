/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_repl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:09:03 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/05 00:29:56 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	get_user_input(t_data *data);
static int	is_valid(char *user_input);
static void	save_input_on_history(char *user_input);

void	init_repl(t_data *data)
{
	data->prompt = "HopeShell:$ ";
	init_repl_signals_handling(data);
	while (1)
	{
		get_user_input(data);
		if (!is_valid(data->user_input))
			break ;
		save_input_on_history(data->user_input);
		//execute_built_in(data);
		init_lexer(data);
		init_expander(data); //se o usuário mandou alguma var de ambiente  --- $
		
		//print p teste
	/*	t_token *aux_print = data->tokens;
		while (aux_print)
		{
			ft_printf("%s\n", aux_print->content);
			aux_print = aux_print->next;
		}*/
		//
		token_clear(&data->tokens); //p teste --isso vem dps --talvez no end_program e exit_error
		// init_parser(data);
		// init_executor(data);
		free(data->user_input);
	}
}

static void	save_input_on_history(char *user_input)
{
	int	i;

	i = 0;
	while (user_input[i] == '\t' || user_input[i] == ' ')
		i++;
	if (user_input[i] != '\0')
		add_history(user_input); //p n salvar historico vazio
}

static int	is_valid(char *user_input)
{
	if (!user_input)
	{
		ft_printf("exit\n"); //ele deve printar exit?
		return (0);
	}
	return (1);
}

static void	get_user_input(t_data *data)
{
	data->user_input = readline(data->prompt);
}
